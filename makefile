all: main.o calcsum.o
	gcc -o main main.o calcsum.o

dolibs: calcsum.c calcsum.h
	gcc -c calcsum.c
	
domain: main.c calcsum.h
	gcc -c main.c
	
clean:
	rm main main.o calcsum.o

.PHONY: all clean
