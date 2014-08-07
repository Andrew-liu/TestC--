.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01open 02fopen 03fileno 04open 05open 06open 07open \
	08open
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
