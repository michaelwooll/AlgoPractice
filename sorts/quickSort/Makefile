run: main.o quickSort.o
	g++ -Wall -pedantic -g main.o quickSort.o -o run

main.o: main.cpp
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp

mergeSort.o: mergeSort.cpp
	g++ -c -Wall -pedantic -g -std=c++11 quicksort.cpp

clean:
	rm *.o run
