.PHONY: clean all
CCFLAGS = -Wall
target = program
sources = main.cpp Array.cpp
objects = main.o Array.o

all: program
	@echo "Build successful!"

program: main.o Array.o
	g++ $(CCFLAGS) $(objects) -o $(target)

main.o: main.cpp
	g++ $(CCFLAGS) -c main.cpp	
	
Array.o: Array.cpp
	g++ $(CCFLAGS) -c Array.cpp	

clean:
	rm -f $(objects) $(target)