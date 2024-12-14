CC = g++
CCFLAG = -g -w
prog3: main.o Matrix.o
	$(CC) $(CCFLAG) -o proj4 main.o Matrix.o
Main.o: main.C
	$(CC) $(CCFLAG) -c -o main.o main.C
Vector.o: Matrix.C Matrix.h
	$(CC) $(CCFLAG) -c -o Matrix.o Matrix.C
clean:
	rm -rf proj4 *.o