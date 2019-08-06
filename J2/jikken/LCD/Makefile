INCLUDE = /home/class/common/NI_USB-6501/include
LIBS    = /home/class/common/NI_USB-6501/lib
CFLAGS  = -g

.c.o:
	gcc $(CFLAGS) -c $< -I$(INCLUDE)

BIN =	LCD_01\
	LCD_02\
	LCD_03\
	LCD_04\
	LCD_05\
	LCD_06\
	LCD_07\
	LCD_08\
	LCD_09\
	LCD_10


all: $(BIN)


clean:
	rm -f *.o
	rm -f $(BIN)


LCD_01:	 	LCD_01.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_02:		LCD_02.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_03:		LCD_03.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_04:		LCD_04.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_05:		LCD_05.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_06:		LCD_06.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_07:		LCD_07.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_08:		LCD_08.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_09:		LCD_09.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb

LCD_10:		LCD_10.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -lusb
