CMD_PATH = /usr/local/bin

CC = $(CMD_PATH)/h8300-hms-gcc
LD = $(CMD_PATH)/h8300-hms-ld
OBJCOPY = $(CMD_PATH)/h8300-hms-objcopy
SIZE = $(CMD_PATH)/h8300-hms-size

INCLUDES = -I./include
CFLAGS = -mh -mrelax -mint32 -O2 $(INCLUDES) -Wall

#
# $B%k!<%k(B
#

all: \
		ramcrt-dbg.o \
		ramcrt-ext.o \
		ramcrt.o \
		romcrt-8k.o \
		romcrt-ext.o

clean :
	rm -f *.o

#
# $B%5%U%#%C%/%9%k!<%k(B
#
.s.o:
	$(CC) -c $(CFLAGS) $<
