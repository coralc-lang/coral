#!/usr/bin/env python3
"""Report the source text of every ERROR node, bucketed by frequency."""
import subprocess, sys, pathlib, collections, re, os

ROOT = pathlib.Path('/home/cerie/Documents/coralc')
GRAMMAR_DIR = ROOT / 'coral-zed' / 'grammars' / 'coral'
ERR_RE = re.compile(r'\(ERROR \[(\d+), (\d+)\] - \[(\d+), (\d+)\]')

def parse(path):
    r = subprocess.run(['tree-sitter', 'parse', str(path)], cwd=GRAMMAR_DIR,
                       capture_output=True, text=True)
    return r.stdout

def nodes_of(src_lines, out):
    """Yield (row, col, text) for every ERROR/MISSING node."""
    res = []
    for m in ERR_RE.finditer(out):
        r0, c0, r1, c1 = (int(x) for x in m.groups())
        if r0 == r1:
            txt = src_lines[r0][c0:c1]
        else:
            txt = src_lines[r0][c0:] + ' ⏎' + ' ⏎'.join(
                src_lines[r][1:70] for r in range(r0 + 1, min(r1 + 1, len(src_lines))))
        res.append((r0, txt.strip()))
    return res

def main():
    args = sys.argv[1:]
    files = []
    if args:
        files = [pathlib.Path(a) for a in args]
    else:
        for rel in ('lib', 'wallvm'):
            files += sorted(ROOT.glob(f'{rel}/**/*.crl'))
        files.append(ROOT / 'print.crl')

    bucket = collections.Counter()
    examples = collections.defaultdict(list)
    total = 0
    for f in files:
        out = parse(f)
        if '(ERROR' not in out and '(MISSING' not in out:
            continue
        src = f.read_text(errors='replace').split('\n')
        for row, txt in nodes_of(src, out):
            if not txt:
                continue
            key = txt[:78]
            bucket[key] += 1
            if len(examples[key]) < 2:
                examples[key].append(f'{f.relative_to(ROOT)}:{row+1}')
            total += 1
    for k, v in bucket.most_common(45):
        print(f'{v:6d}  {k!r}')
        for e in examples[k][:1]:
            print(f'          {e}')
    print(f'\n{total} error nodes over {len(files)} files')

main()
