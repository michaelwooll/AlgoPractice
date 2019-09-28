run: main.o hash.o
	g++ -Wall -pedantic -g main.o hash.o -o run

main.o: main.cpp
	g++ -c -Wall -pedantic -g -std=c++11 main.cpp

hash.o: hash.cpp
	g++ -c -Wall -pedantic -g -std=c++11 hash.cpp

clean:
	rm *.o run
