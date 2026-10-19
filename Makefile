# coralc — build the compiler executables from the packaged C sources.
#
#   make            build the host executable (linux on Linux, windows on Windows)
#   make linux      build dist/coralc-linux-x86_64 from dist/coralc-linux.c
#   make windows    build dist/coralc-windows-x86_64.exe from dist/coralc-windows.c
#   make install    install the host executable + lib/ into $(PREFIX) (default ~/.coral)
#   make package    regenerate dist/coralc-{linux,windows}.c (internal, no binaries)
#   make clean      remove built executables (the C sources are kept)
#
# The C sources carry the default std platform baked at package time;
# --platform overrides it at run time.

ifeq ($(OS),Windows_NT)
  HOST     := windows
  EXE      := .exe
  HOST_BIN := dist/coralc-windows-x86_64.exe
  MINGW    ?= gcc
else
  HOST     := linux
  EXE      :=
  HOST_BIN := dist/coralc-linux-x86_64
  MINGW    ?= x86_64-w64-mingw32-gcc
endif

CC      ?= cc
PREFIX  ?= $(HOME)/.coral
LINUX_C   := $(wildcard dist/coralc-linux.c)
WINDOWS_C := $(wildcard dist/coralc-windows.c)
BOOT_SEED := compiler/build/coralc
BOOT_C    := compiler/build/coralc.c

.PHONY: all linux windows install package clean

all: $(HOST)

linux: dist/coralc-linux-x86_64

windows: dist/coralc-windows-x86_64.exe

# Packaged C when present; otherwise bootstrap the tracked seed/C and
# selfhost the current sources (Linux only — Windows needs the packaged C).
dist/coralc-linux-x86_64: $(LINUX_C)
	@mkdir -p dist
	@if [ -n "$(LINUX_C)" ]; then \
		echo "build: $(CC) $<"; \
		$(CC) -std=gnu11 -O0 -o $@ "$<" -lm; \
	elif [ -x "$(BOOT_SEED)" ]; then \
		echo "build: bootstrap $(BOOT_SEED), then selfhost"; \
		cp "$(BOOT_SEED)" .bootstrap-coralc-linux; \
		( cd compiler && ../.bootstrap-coralc-linux build --force --flag '{host=linux}' ) && \
		cp compiler/build/coralc $@; rc=$$?; rm -f .bootstrap-coralc-linux; \
		exit $$rc; \
	elif [ -f "$(BOOT_C)" ]; then \
		echo "build: $(CC) $(BOOT_C), then selfhost"; \
		$(CC) -std=gnu11 -O0 -o .bootstrap-coralc-linux "$(BOOT_C)" -lm; \
		( cd compiler && ../.bootstrap-coralc-linux build --force --flag '{host=linux}' ) && \
		cp compiler/build/coralc $@; rc=$$?; rm -f .bootstrap-coralc-linux; \
		exit $$rc; \
	else \
		echo "error: no dist/coralc-linux.c, $(BOOT_SEED) or $(BOOT_C)" >&2; \
		exit 1; \
	fi

dist/coralc-windows-x86_64.exe: $(WINDOWS_C)
	@if [ -z "$(WINDOWS_C)" ]; then \
		echo "error: dist/coralc-windows.c is missing; run ./package.sh on a build host and commit it" >&2; \
		exit 1; \
	fi
	@command -v "$(MINGW)" >/dev/null 2>&1 || { \
		echo "error: $(MINGW) not found (install mingw-w64 or w64devkit)"; exit 1; }
	$(MINGW) -std=gnu11 -O0 -o $@ "$(WINDOWS_C)" -lm

install: $(HOST)
	mkdir -p "$(PREFIX)/bin"
	cp "$(HOST_BIN)" "$(PREFIX)/bin/coralc$(EXE)"
	rm -rf "$(PREFIX)/lib"
	cp -R lib "$(PREFIX)/lib"

package:
	./package.sh

clean:
	rm -f dist/coralc-linux-x86_64 dist/coralc-windows-x86_64.exe
