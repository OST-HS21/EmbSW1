#
# Makefile fuer Counter-Programm
# File: makefile
# Reto Bonderer, 24.11.2010
#
CC = gcc
LINK = gcc
# '-pedantic' sorgt dafuer, dass gcc streng arbeitet
#CFLAGS = -c -pedantic
#LFLAGS = -pedantic
CFLAGS = -c -Wall
LFLAGS = -Wall
OBJS = counter.o counterCtrl.o counterTest.o
EXE = counterTest

$(EXE): $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

counterTest.o: counterTest.c counterCtrl.h
	$(CC) $(CFLAGS) counterTest.c

counter.o: counter.c counter.h
	$(CC) $(CFLAGS) counter.c

counterCtrl.o: counterCtrl.c counterCtrl.h counter.h
	$(CC) $(CFLAGS) counterCtrl.c

clean:
	rm -f $(EXE) $(OBJS)
