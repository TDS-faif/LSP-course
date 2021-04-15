all: main.o calcsum.o
	sleep 10
	gcc -o main main.o calcsum.o

dolibs: calcsum.c calcsum.h
	sleep 10
	gcc -c calcsum.c
	
domain: main.c calcsum.h
	sleep 10
	gcc -c main.c
	
clean:
	rm main main.o calcsum.o

.PHONY: all clean
