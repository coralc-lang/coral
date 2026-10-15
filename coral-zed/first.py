#!/usr/bin/env python3
"""Show the first ERROR of each .crl file — i.e. the root cause."""
import subprocess, pathlib, re

ROOT = pathlib.Path('/home/cerie/Documents/coralc')
GRAMMAR = ROOT / 'coral-zed' / 'grammars' / 'coral'
ERR = re.compile(r'\(ERROR \[(\d+), (\d+)\] - \[(\d+), (\d+)\]')

def files():
    for rel in ('lib', 'wallvm'):
        yield from sorted(ROOT.glob(f'{rel}/**/*.crl'))
    yield ROOT / 'print.crl'

def main():
    out = []
    for f in files():
        r = subprocess.run(['tree-sitter', 'parse', str(f)], cwd=GRAMMAR,
                           capture_output=True, text=True)
        m = ERR.search(r.stdout)
        if not m:
            continue
        r0, c0, r1, _c1 = (int(x) for x in m.groups())
        src = f.read_text(errors='replace').split('\n')
        line = src[r0]
        snip = line[c0:c0 + 70] if r0 == r1 else line[c0:].strip()[:70]
        out.append(f'{f.relative_to(ROOT)}:{r0 + 1}: {snip.strip()!r}')
    print('\n'.join(out))
    print(f'\n{len(out)} files with errors')

main()
