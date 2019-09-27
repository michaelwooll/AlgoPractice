run: main.o mergeSort.o
	g++ -Wall -pedantic -g main.o mergeSort.o -o run

main.o: main.cpp
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp

mergeSort.o: mergeSort.cpp
	g++ -c -Wall -pedantic -g -std=c++11 mergeSort.cpp

clean:
	rm *.o run
