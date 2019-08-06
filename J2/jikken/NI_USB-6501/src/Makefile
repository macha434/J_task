INCLUDE = /home/class/common/NI_USB-6501/include
LIBS    = /home/class/common/NI_USB-6501/lib
CFLAGS  = -g 

.c.o:
	gcc $(CFLAGS) -c $< -I$(INCLUDE)

BIN =	write_data \
	read_data


all: $(BIN)


clean:
	rm -f *.o
	rm -f $(BIN)


write_data:	 	write_data_main.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

read_data:	 	read_data_main.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb
