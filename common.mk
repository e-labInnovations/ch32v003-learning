# Shared settings for all every lesson. Include it before ch32fun.mk

CH32FUN_ROOT	?= ../../ch32fun
CH32FUN				?= $(CH32FUN_ROOT)/ch32fun
MINICHLINK		?= $(CH32FUN_ROOT)/minichlink

# Ubuntu ships picolibc, not newlib. ch32fun.mk defaults to /usr/includes/newlib,
# Which does not exist here, and the build dies on "stdio.h: No such file". So we override it here.
NEWLIB				?= /usr/include/picolibc/riscv64-unknown-elf/include

TARGET_MCU		?= CH32V003

# My CH549 SWIO probe, talkingthe ardulink protocol over USB-CDC.
# Use '=' (lazy), never ':=' (immediate)
FLASH_COMMAND	= $(MINICHLINK)/minichlink $(PROGRAMMER_ARGS) -w $< flash -b