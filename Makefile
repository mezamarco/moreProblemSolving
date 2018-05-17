all: main nQueensProblem

main: main.o
	g++ -g -o main main.o


main.o: main.cpp
	g++ -c -g main.cpp



nQueensProblem: nQueensProblem.o
	g++ -g -o nQueensProblem nQueensProblem.o

nQueensProblem.o: nQueensProblem.cpp
	g++ -c -g nQueensProblem.cpp



clean:
	rm *.o *.exe
