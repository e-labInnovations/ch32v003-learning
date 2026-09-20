TARGET	:= main

include ../common.mk

all		: $(TARGET).bin
flash	: cv_flash
clean	: cv_clean

# printf-over-SWIO viewer. Ctrl+C to quite.
# NOTE: do not name this target 'monitor' or 'terminal' - chf32fun.mk already define both,
# and make will warn about overridden recipe.
console	:
	$(MINICHLINK)/minichlink $(PROGRAMMER_ARGS) -T

# Read the chip back, erase it, show info
info	:
	$(MINICHLINK)/minichlink $(PROGRAMMER_ARGS) -i
erase	:
	$(MINICHLINK)/minichlink $(PROGRAMMER_ARGS) -E

.PHONY: all flash clean console info erase

include $(CH32FUN)/ch32fun.mk