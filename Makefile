CC = g++

all:
	$(CC) -std=c++14 -o a.exe ecun.cpp

clean:
	rm -f a.exe

