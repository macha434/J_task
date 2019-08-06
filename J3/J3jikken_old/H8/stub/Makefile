#
# gdb-h8-stub/Makefile
#


CROSS_COMPILE=/usr/local/h8/bin/h8300-hms-

CC      = $(CROSS_COMPILE)gcc -I.
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

CFLAGS		 = -O2 -g
AFLAGS		+= -mgas

CFLAGS		+= -mh -mint32
AFLAGS		+= -mh -mint32 

CFLAGS		+= -pipe
LINKSCRIPT	 = h8-stub.lds.s
LINKFLAGS	+= -T $(word 1,$(LINKSCRIPT)) -e _start -Map h8-stub.map

ADJUST_VMA = 0

OBJECTS=\
	head.o\
	entry.o\
	isr.o\
	h8-sci.o\
	h8-stub.o\
	string.o

.s.o:
	$(CC)  -c -mh -mint32 -o $*.o $<
#	$(CC) -D__ASSEMBLY__ $(AFLAGS) -traditional -c -o $*.o $<

h8-stub.mot: h8-stub
	$(OBJCOPY) -S -g -R .data -R .bss -R .stack -R .comment -O srec \
		h8-stub h8-stub.mot

h8-stub.elf: h8-stub
	$(OBJCOPY) -S -R .data -R .stack -R .bss -R .comment \
	--adjust-vma=${ADJUST_VMA} \
	h8-stub h8-stub.elf

h8-stub.hex: h8-stub
	$(OBJCOPY) -S -R .data -R .stack -R .bss -R .comment \
		--adjust-vma=${ADJUST_VMA} -O ihex \
		h8-stub h8-stub.hex

h8-stub.bin: h8-stub
	$(OBJCOPY) -S -g -R .data -R .stack -R .bss -R .comment -O binary \
		h8-stub h8-stub.bin

h8-stub: ${OBJECTS} h8-stub.lds
	$(LD) $(LINKFLAGS) ${OBJECTS} \
		-o h8-stub

h8-stub.lds: h8-stub.lds.s
	$(CC) $(CFLAGS) -E -C -P -I. h8-stub.lds.s >h8-stub.lds

all: h8-stub.elf h8-stub.bin h8-stub.hex h8-stub.mot
clean:
	rm -f h8-stub h8-stub.bin h8-stub.elf h8-stub.mot h8-stub.hex *.o h8-stub.lds h8-stub.map

