INCLUDE = /home/class/common/NI_USB-6501/include
LIBS = /home/class/common/NI_USB-6501/lib
LDFLAGS = -L/usr/lib64

CC = g++
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

