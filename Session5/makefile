COMPLIER = g++
CCFLAGS = -g -Wall
project: prog3.cpp min.o max.o average.o
	$(COMPLIER) $(CCFLAGS) -o project prog3.cpp max.o min.o average.o

max.o: max.cpp max.h
	$(COMPLIER) $(CCFLAGS) -c -o max.o max.cpp
min.o: min.cpp min.h
	$(COMPLIER) $(CCFLAGS) -c -o min.o min.cpp
average.o: average.cpp average.h
	$(COMPLIER) $(CCFLAGS) -c -o average.o average.cpp

clean:
	rm -f *.o project