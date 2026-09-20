# CH32V003 Learning

Small, self-contained C lessons for the WCH CH32V003 microcontroller using
[ch32fun](../ch32fun) and a [CH549 SWIO probe](https://github.com/e-labInnovations/ch549-link)
running the Ardulink protocol.

For the complete setup notes, hardware wiring, API reference, VS Code guidance,
lesson plan, and troubleshooting, read the companion book:

**[CH32V003 + ch32fun self-study book](../ch32v003-learning-book/README.md)**

## Repository layout

```text
common.mk       Shared toolchain, ch32fun, and programmer settings
_template/      Starting point for a new lesson
01-blink/       Blink example
02-printf/      printf over the SWIO debug link
.vscode/        VS Code IntelliSense configuration
```

Each lesson is an independent Make project containing `main.c`, `funconfig.h`,
and `Makefile`. The shared settings in `common.mk` keep paths and flash options
consistent across lessons.

## Prerequisites

The current configuration expects:

- `riscv64-unknown-elf-gcc` and the matching binutils on `PATH`
- the `ch32fun` checkout at `../ch32fun`
- picolibc headers at `/usr/lib/picolibc/riscv64-unknown-elf/include`
- a CH549 probe available as `/dev/ttyACM0`
- the target powered at 3.3 V and connected to the probe's SWIO line

The probe defaults are configured in `common.mk`:

```make
PROGRAMMER_ARGS ?= -C ardulink -c /dev/ttyACM0
```

Override them on the command line when necessary:

```bash
make PROGRAMMER_ARGS="-C other-mode" flash
```

## Build and flash

Run commands from a lesson directory:

```bash
cd 01-blink
make          # Build main.elf, main.bin, main.hex, and main.lst
make flash    # Build and flash the target
make console  # View printf output; press Ctrl+C to exit
make info     # Show chip information
make erase    # Erase the target
make clean    # Remove generated lesson files
```

The `console` target and flashing cannot use the serial device at the same time.
Close the console before running `make flash`.

## Start a new lesson

Copy the template, then edit the new lesson's source and configuration:

```bash
cp -r _template 03-button
cd 03-button
$EDITOR main.c funconfig.h
make flash
```

Keep the `ch32fun` checkout unchanged. Put experiments in lesson directories so
each working example remains available as a reference.
