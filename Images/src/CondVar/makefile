#
# Makefile Condition Variable
# File: makefile
# Reto Bonderer, 13.11.2020
#
CC = clang
LINK = clang

CFLAGS = -c -Wall -pthread
LFLAGS = -Wall -lpthread
OBJS = condvar.o
EXE = condvar

$(EXE): $(OBJS)
	$(LINK) -o $(EXE) $(OBJS) $(LFLAGS)

condvar.o: condvar.c
	$(CC) $(CFLAGS) condvar.c

clean:
	rm -f $(EXE) $(OBJS)
