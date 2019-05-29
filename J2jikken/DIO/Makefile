INCLUDE = /home/class/common/NI_USB-6501/include
LIBS    = /home/class/common/NI_USB-6501/lib
CFLAGS  = -g 

.c.o:
	gcc $(CFLAGS) -c $< -I$(INCLUDE)

BIN =	write_data \
	read_data \
	LED_blink \
	LED_Lshift \
	LED_Lrotate \
	switch_LED \
	abc


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

LED_blink:	 	LED_blink_main.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LED_Lshift:	 	LED_Lshift_main.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LED_Lrotate:	 	LED_Lrotate_main.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

switch_LED:	 	switch_LED_main.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

abc:	 		a.o \
			$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

