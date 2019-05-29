INCLUDE = /home/class/common/NI_USB-6501/include
LIBS    = /home/class/common/NI_USB-6501/lib
CFLAGS  = -g 

.c.o:
	gcc $(CFLAGS) -c $< -I$(INCLUDE)

BIN =	prog1


all: $(BIN)


clean:
	rm -f *.o
	rm -f $(BIN)


prog1:	 	prog1.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

