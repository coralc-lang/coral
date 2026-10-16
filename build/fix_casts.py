#!/usr/bin/env python3
"""Insert explicit casts at TC-0002 mismatch sites (bottom-up per file).

Reads a coralc -ferror-limit=0 dry-run log; for messages of the form
`got X, expected Y` inserts `(<Y>)` before the token at the reported
column when that token is a string literal or an integer literal.
"""
import re
import sys
from collections import defaultdict

LOG = sys.argv[1] if len(sys.argv) > 1 else "build/errdump7.log"
ROOT = "compiler-new"

ARROW = re.compile(r"┌─► \./([^:]+):(\d+):(\d+)")


def parse_errors(log_path):
    out = []
    lines = open(log_path, encoding="utf-8").read().splitlines()
    i = 0
    while i < len(lines):
        m = re.match(r"^error\[TC-0002\]: (.*)$", lines[i])
        if m:
            msg = m.group(1)
            j = i + 1
            arrow = None
            while j < len(lines) and j < i + 10:
                a = ARROW.search(lines[j])
                if a:
                    arrow = a
                    break
                if lines[j].startswith("error["):
                    break
                j += 1
            if arrow:
                g = re.search(r"got `([^`]+)`, expected `([^`]+)`", msg)
                if g:
                    out.append((arrow.group(1), int(arrow.group(2)),
                                int(arrow.group(3)), g.group(1), g.group(2), msg))
        i += 1
    return out


def cast_for(got, expected, token):
    if token.startswith('"'):
        if got == "str" and expected in ("u8*", "cchar*", "char*"):
            return "(u8*)"
    if re.match(r"^[0-9]", token):
        if expected in ("usize", "u32", "u64", "i32", "i64", "isize", "u16", "i16", "u8", "i8"):
            if got in ("i64", "i32", "usize", "u32", "u64", "isize"):
                return f"({expected})"
    return None


def main():
    errs = parse_errors(LOG)
    by_file = defaultdict(list)
    seen = set()
    for path, line, col, got, expected, msg in errs:
        key = (path, line, col)
        if key in seen:
            continue
        seen.add(key)
        by_file[path].append((line, col, got, expected, msg))

    total = 0
    per_file = []
    for path, sites in sorted(by_file.items()):
        full = f"{ROOT}/{path}"
        try:
            lines = open(full, encoding="utf-8").read().splitlines(keepends=True)
        except OSError:
            continue
        fixed = 0
        skipped = 0
        for line, col, got, expected, msg in sorted(sites, reverse=True):
            if line - 1 >= len(lines):
                skipped += 1
                continue
            text = lines[line - 1]
            idx = col - 1
            rest = text[idx:]
            tok = rest.lstrip()
            if not tok:
                skipped += 1
                continue
            cast = cast_for(got, expected, tok)
            if cast is None:
                skipped += 1
                continue
            pad = idx + (len(rest) - len(tok))
            if text[pad:pad + len(cast)] == cast:
                continue
            lines[line - 1] = text[:pad] + cast + text[pad:]
            fixed += 1
        if fixed:
            open(full, "w", encoding="utf-8").writelines(lines)
            per_file.append((path, fixed, skipped))
            total += fixed
    for p, f, s in per_file:
        print(f"{p}: cast {f} (skipped {s})")
    print(f"TOTAL casts inserted: {total}")


if __name__ == "__main__":
    main()
