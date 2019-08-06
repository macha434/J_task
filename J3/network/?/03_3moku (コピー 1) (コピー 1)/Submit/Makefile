#*********************************************/
#*       File name:  Makefile                */
#*    Project name:  socket/3moku            */
#*      Month/Year:  Jan/2003                */
#*          Author:  Shuichi YUKITA          */
#*********************************************/

MYLIBDIR =  ../../mylib
MYLIB    =  $(MYLIBDIR)/mylib.a
CFLAGS   =  -I$(MYLIBDIR)

BIN =	server \
	client \
	server.mod \
	client.mod

all:	$(BIN)

server:	server.o  goban.o
	$(CC) -o $@  $^  $(MYLIB)


server.mod: server.mod.o goban.mod.o
	$(CC) -o $@  $^  $(MYLIB)


client:	client.o  goban.o
	$(CC) -o $@  $^  $(MYLIB)

client.mod: client.mod.o goban.mod.o
	$(CC) -o $@  $^  $(MYLIB)

server.o client.o :	goban.h

server.mod.o client.mod.o : goban.mod.c goban.h

clean:
	$(RM) $(BIN) *.o *~
