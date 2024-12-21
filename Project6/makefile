.PHONY: clean all
CXX = g++
CXXFLAGS = -Wall -g
target = proj6
sources = main.C DNode.cpp DList.cpp DVector.cpp
objects = main.o DNode.o DList.o DVector.o

prog6: $(objects)
	$(CXX) $(CXXFLAGS) -o $(target) $(objects)

Main.o: main.C
	$(CXX) $(CXXFLAGS) -c -o main.o main.C

DNode.o: DNode.cpp DNode.h
	$(CXX) $(CXXFLAGS) -c -o DNode.o DNode.cpp

DList.o: DList.cpp DList.h
	$(CXX) $(CXXFLAGS) -c -o DList.o DList.cpp

DVector.o: DVector.cpp DVector.h
	$(CXX) $(CXXFLAGS) -c -o DVector.o DVector.cpp

clean:
	rm -rf proj6 *.o
