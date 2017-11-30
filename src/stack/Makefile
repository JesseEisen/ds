CC=gcc
SRC= stack.c test.c
OBJ= $(SRC:.c=.o)
CFLAGS= -g -O2

test: $(SRC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ 

.PHONY=clean
clean:
	rm -f test *.o
