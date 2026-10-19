# Packaging coralc

This is our internal release packaging, not the user-facing install path.
`package.sh` emits the compiler **as C** for both platforms, with the
default std platform baked in. It never builds or ships executables.

## Emit the C sources

```sh
./package.sh
```

Outputs in `dist/`:

| file | meaning |
| --- | --- |
| `coralc-linux.c` | compiler C, `host=linux` + `platform=linux` baked |
| `coralc-windows.c` | compiler C, `host=windows` + `platform=windows` baked |

The generated C is compiled with `-O0` on purpose: the current C output
triggers optimizer-sensitive UB at `-O2` (the tracked bootstrap
`compiler/build/coralc.c` hangs when built with `-O2`, works at `-O0`).

## Build executables

The Makefile owns compilation:

```sh
make linux     # dist/coralc-linux-x86_64   from dist/coralc-linux.c
make windows   # dist/coralc-windows-x86_64.exe from dist/coralc-windows.c (mingw)
make           # the host one
make install PREFIX=~/.coral
```

`make windows` needs `x86_64-w64-mingw32-gcc` on a Linux build host; on
Windows it uses `gcc` (w64devkit/mingw-w64).

## How the default platform is baked

`compiler/coral-common/platform.crl` uses a compile-time flag expression:

```coral
pub str hostOs()
{
    return flag (host) {
        windows => "windows",
        else => "linux",
    };
}
```

`package.sh` builds each variant with `host=<platform>` and
`platform=<platform>` in the build file. The first is stored in the binary
as the default std platform; the second selects the platform tree while
compiling the compiler itself. Users can override the default at run time:

```sh
coralc --platform windows app.crl
coralc build              # coral.crlb flags can also say platform=windows
CORAL_PLATFORM=windows coralc build
```

## Install scripts

`install.sh` and `install.ps1` are the user-facing path. They download the
repository when not run from a checkout, invoke the Makefile to compile the
host executable, install the binary under `$CORAL_HOME/bin` (default
`~/.coral`) and `lib/` under `$CORAL_HOME/lib`, then add `$CORAL_HOME/bin`
to the user's PATH.

```sh
curl -fsSL https://raw.githubusercontent.com/coralc-lang/coralc/main/install.sh | sh
```

```powershell
irm https://raw.githubusercontent.com/coralc-lang/coralc/main/install.ps1 | iex
```

The installers need the packaged C files in `dist/` (they are part of the
repository) and a C compiler (`cc` on Linux, `gcc` on Windows).
