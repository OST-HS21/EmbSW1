#
# Makefile fuer Counter-Programm
# File: makefile
# Reto Bonderer, 07.10.2017
#
CC = g++
LINK = g++
CFLAGS = -c -Wall
LFLAGS = -Wall
OBJS = Counter.o CounterCtrl.o counterTest.o
EXE = counterTest

$(EXE): $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

counterTest.o: counterTest.cpp CounterCtrl.h
	$(CC) $(CFLAGS) counterTest.cpp

Counter.o: Counter.cpp Counter.h
	$(CC) $(CFLAGS) Counter.cpp

CounterCtrl.o: CounterCtrl.cpp CounterCtrl.h Counter.h
	$(CC) $(CFLAGS) CounterCtrl.cpp

clean:
	rm -f $(EXE) $(OBJS)
