#
# Makefile fuer Counter-Programm
# File: makefile
# Reto Bonderer, 13.10.2020
#
CC = clang++
LINK = clang++
# '-pedantic' sorgt dafuer, dass gcc streng arbeitet
CFLAGS = -c -pedantic -Wall
LFLAGS = -pedantic
OBJS = Counter.o CounterCtrl.o CounterState.o counterTest.o

counterTest: $(OBJS)
	$(LINK) $(LFLAGS) -o counterTest $(OBJS)

counterTest.o: counterTest.cpp CounterCtrl.h
	$(CC) $(CFLAGS) counterTest.cpp

Counter.o: Counter.cpp Counter.h
	$(CC) $(CFLAGS) Counter.cpp

CounterCtrl.o: CounterCtrl.cpp CounterCtrl.h CounterState.h
	$(CC) $(CFLAGS) CounterCtrl.cpp

CounterState.o: CounterState.cpp CounterState.h Counter.h CounterCtrl.h
	$(CC) $(CFLAGS) CounterState.cpp
  
clean:
	rm -f counterTest $(OBJS)
	
all: clean counterTest

