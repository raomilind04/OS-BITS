bubble.out: main.c bSort.o
	gcc -o bubble.out main.c bSort.o

bSort.o : bubbleSort.c sort.h
	gcc -c bubbleSort.c

clean:
	rm -f *.o *.out