.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN=a.exe
OBJS=main.o add.o 
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
