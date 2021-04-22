threaded: threadedSum.o calcsum.o
	gcc -o threadedSum threadedSum.o calcsum.o -lpthread

normal: main.o calcsum.o
	gcc -o main main.o calcsum.o

compilelibs: calcsum.c calcsum.h
	gcc -c calcsum.c
	
compileThreaded: threadedSum.c calcsum.h
	gcc -c threadedSum.c
	
compilemain: main.c calcsum.h
	gcc -c main.c

clean:
	rm main threadedSum main.o calcsum.o threadedSum.o

.PHONY: all clean
