INCLUDE = /home/jugyou/NI_USB-6501/include
LIBS =  /home/jugyou/NI_USB-6501/lib
CFLAGS = -g

.c.o:
	gcc $(CFLAGS) -c $< -I$(INCLUDE)

BIN =	LCD_01


ALL: $(BIN)


clean:
	rm -f *.o
	rm -f $(BIN)


LCD_01:	 	LCD_01.o \
		$(LIBS)/niusb6501.o
	gcc -o $@ $^ -L$(LIBS) -lusb

