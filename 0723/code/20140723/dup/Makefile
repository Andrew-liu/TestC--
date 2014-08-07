.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01dup 02dup 03dup2 04redirect 05redirect 06fcntl
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
