.PHONY: build clean

build: a.out

clean: 
	rm -f *.o a.out

a.out: main.cpp log.o
	g++ main.cpp log.o -lpthread


log.o: log.cpp log.hpp
	g++ -c log.cpp -lpthread
