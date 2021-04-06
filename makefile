.PHONY: build clean

build: a.out

clean: 
	rm -f *.o a.out

a.out: main.o log.o
	g++ main.o log.o

main.o: main.cpp
	g++ -c main.cpp

log.o: log.cpp
	g++ -c log.cpp
