COMPILER = g++
CFLAGS   = $(shell pkg-config --cflags raylib)
LDFLAGS  = $(shell pkg-config --libs raylib)
STD=-std=c++11

run: main
	./main

main: main.cpp
	$(COMPILER) $(CFLAGS) main.cpp -o main $(LDFLAGS) $(STD)

clean:
	rm -f main

