driver.out: driver.o vector.o
	gcc driver.o vector.o -o driver.out

driver.o: driver.c
	gcc -c driver.c -o driver.o

vector.o: vector.c vector.h
	gcc -c vector.c -o vector.o

.PHONY: 
	clean; 

clean:
	rm driver.out *.o