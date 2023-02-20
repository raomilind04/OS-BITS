driver.out : stackDriver.o stackOps.o
	gcc stackDriver.o stackOps.o -o driver.out

stackDriver.o : stackDriver.c
	gcc -c stackDriver.c -o stackDriver.o

stackOps.o : stackOps.c stackOps.h
	gcc -c stackOps.c -o stackOps.o

clean : 
	rm driver.out *.o