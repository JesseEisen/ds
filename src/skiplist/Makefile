CC=gcc
SRC= skiplist.c example.c
OBJ= $(SRC:.c=.o)
CFLAGS= -pg -g -O2

example: $(SRC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -c -o $@ 

.PHONY=clean
clean:
	rm -f example *.o *.out *.dSYM
