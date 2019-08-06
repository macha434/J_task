INCLUDE = /home/jugyou/common/NI_USB-6501/include
LIBS = /home/jugyou/common/NI_USB-6501/lib
LDFLAGS = -L/usr/lib64

CC = gcc
RM = rm -f

TARGETS = demo

all: $(TARGETS)

demo: demo.o ./niusb6501.o
##	$(CC) -L$(LIBS) -lusb -o $@ $+
	$(CC) -lusb -o $@ $+

%.o: %.c
	$(CC) -O3 -o $@ -c $< -I$(INCLUDE) -fPIC

clean:
	$(RM) *.o $(TARGETS)

.PHONY: all clean

