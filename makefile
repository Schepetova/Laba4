GFLAGS = -g
all: human.o main.o laba

human.o: human.cpp
	g++ $(CFLAGS) -c -o human.o human.cpp

main.o: main.cpp
	g++ $(CFLAGS) -c -o main.o main.cpp

laba: human.o main.o 
	g++ main.o human.o -o laba
clean:
	rm -f *.o
