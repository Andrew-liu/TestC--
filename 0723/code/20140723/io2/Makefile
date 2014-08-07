.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01lseek 02lseek 03lseek 04hole 05hole 06opendir
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
