driver.out : main.o bubbleSort.o mergeSort.o
	gcc main.o bubbleSort.o mergeSort.o -o driver.out

main.o : main.c
	gcc -c main.c -o main.o

bubbleSort.o : bubbleSort.c sort.h
	gcc -c bubbleSort.c -o bubbleSort.o

mergeSort.o : mergeSort.c sort.h
	gcc -c mergeSort.c -o mergeSort.o

clean : 
	rm driver.out *.o