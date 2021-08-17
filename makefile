CFLAGS=-Wall -Werror -pedantic -Wextra -Wconversion -std=gnu11 -lm

tp2: tp2.o myFuncs.o meminfo.o
	gcc $(CFLAGS) -o tp2 myFuncs.o meminfo.o tp2.o

tp2.o: tp2.c 
	gcc $(CFLAGS) -c tp2.c

myFuncs.o: myFuncs.c myFuncs.h
	gcc $(CFLAGS) -c myFuncs.c

meminfo.o: meminfo.c meminfo.h myFuncs.h
	gcc $(CFLAGS) -c meminfo.c

clean:
	rm -f *.o tp2