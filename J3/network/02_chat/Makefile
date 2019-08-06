BIN=	server \
	server.mod \
	client \
	client.mod 

all : $(BIN)

clean:
	rm -f *.c~
	rm -f $(BIN)

server:	server.c \
			$(LIBS)
	gcc -o $@ $^

server.mod:	server.mod.c \
			$(LIBS)
	gcc -o $@ $^

client:	client.c \
			$(LIBS)
	gcc -o $@ $^

client.mod:	client.mod.c \
			$(LIBS)
	gcc -o $@ $^
