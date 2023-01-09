#
# Makefile fuer Counter-Programm
# File: makefile
# Reto Bonderer, 13.10.2020
#
CC = clang++
LINK = clang++
# '-pedantic' sorgt dafuer, dass g++ streng arbeitet
CFLAGS = -c -pedantic -Wall
LFLAGS = -pedantic
OBJS = Counter.o CounterCtrl.o CounterState.o counterTest.o
EXE = counterTest

$(EXE): $(OBJS)
	$(LINK) $(LFLAGS) -o $(EXE) $(OBJS)

counterTest.o: counterTest.cpp CounterCtrl.h
	$(CC) $(CFLAGS) counterTest.cpp

Counter.o: Counter.cpp Counter.h
	$(CC) $(CFLAGS) Counter.cpp

CounterCtrl.o: CounterCtrl.cpp CounterCtrl.h CounterState.h
	$(CC) $(CFLAGS) CounterCtrl.cpp

CounterState.o: CounterState.cpp CounterState.h Counter.h
	$(CC) $(CFLAGS) CounterState.cpp
  
clean:
	rm -f $(EXE) $(OBJS)
	
all: clean $(EXE)
	
