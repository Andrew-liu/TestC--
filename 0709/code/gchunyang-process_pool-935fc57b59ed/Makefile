.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN=server
OBJS=main.o sysutil.o select_t.o process_pool.o 
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
