#!/usr/bin/env python3
"""Run each .crl snippet in snippets/ through tree-sitter parse."""
import subprocess, sys, pathlib

ROOT = pathlib.Path(__file__).resolve().parent
GRAMMAR = ROOT / "grammars" / "coral"
SNIPPETS = ROOT / "test" / "snippets"

def run(p):
    r = subprocess.run(["tree-sitter", "parse", str(p)], cwd=GRAMMAR,
                       capture_output=True, text=True)
    return r.stdout + r.stderr

def main():
    only = sys.argv[1] if len(sys.argv) > 1 else None
    files = sorted(SNIPPETS.glob("*.crl"))
    if only:
        files = [f for f in files if only in f.name]
    bad = 0
    for f in files:
        out = run(f)
        if "ERROR" in out or "MISSING" in out:
            bad += 1
            print(f"FAIL  {f.name}")
            for line in out.splitlines():
                if "ERROR" in line or "MISSING" in line:
                    print("        " + line.strip()[:160])
        else:
            print(f"ok    {f.name}")
    print(f"\n{len(files) - bad}/{len(files)} snippets parse cleanly")
    return 1 if bad else 0

if __name__ == "__main__":
    sys.exit(main())
