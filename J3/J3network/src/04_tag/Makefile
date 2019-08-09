#*********************************************/
#*       File name:  Makefile                */
#*    Project name:  socket/tag              */
#*      Month/Year:  Jan/2003                */
#*          Author:  Shuichi YUKITA          */
#*********************************************/

MYLIBDIR = ../mylib
MYLIB    = $(MYLIBDIR)/mylib.a
CFLAGS   = -I$(MYLIBDIR)

BIN =	server \
	client \
	server.mod \
	client.mod


all:	$(BIN)

clean:
	$(RM)  $(BIN) *.o *~

server.o client.o:	tag.h \
			session.h

server.mod.o client.mod.o:	tag.h \
				session.mod.c	\
				session.h

server:	server.o  session.o
	$(CC) -o $@  $^  $(MYLIB)  -lcurses

client:	client.o  session.o
	$(CC) -o $@  $^  $(MYLIB)  -lcurses

server.mod:	server.mod.o session.mod.o
	$(CC) -o $@ $^  $(MYLIB)  -lcurses

client.mod:	client.mod.o session.mod.o
	$(CC) -o $@ $^  $(MYLIB)  -lcurses
