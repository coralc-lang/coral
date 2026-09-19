import sys
import os

def main():
    if len(sys.argv) < 2:
        print("usage: coralc <file.crl> [-o output]")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = "a.out"
    if "-o" in sys.argv:
        idx = sys.argv.index("-o")
        output_path = sys.argv[idx + 1]

    with open(input_path, "r") as f:
        source = f.read()

    from lexer import Lexer
    from parser import Parser
    from codegen import CodeGen

    lexer = Lexer(source, input_path)
    tokens = lexer.lex()

    parser = Parser(tokens, input_path)
    ast = parser.parse()

    gen = CodeGen()
    c_code = gen.generate(ast)

    c_path = output_path + ".c"
    with open(c_path, "w") as f:
        f.write(c_code)

    print(f"wrote {c_path}")

    cc = os.environ.get("CC", "gcc")
    cmd = f'{cc} -o {output_path} {c_path} -lgcc'
    print(f"{cmd}")
    ret = os.system(cmd)
    if ret != 0:
        print("compilation failed")
        sys.exit(1)

    os.remove(c_path)
    print(f"wrote {output_path}")

if __name__ == "__main__":
    main()
