CXX = g++
CXXFLAGS = -g
prog5a: main.o Matrix.o
	$(CXX) $(CXXFLAGS) -o proj5 main.o Matrix.o
Main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp
Matrix.o: Matrix.cpp Matrix.hpp
	$(CXX) $(CXXFLAGS) -c -o Matrix.o Matrix.cpp
clean:
	rm -rf proj5 *.o