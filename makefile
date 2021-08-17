CFLAGS=-Wall -Werror -pedantic

tp2: tp2.o myFuncs.o meminfo.o cpuinfo.o version.o
	gcc $(CFLAGS) -o tp2 myFuncs.o meminfo.o cpuinfo.o version.o tp2.o

tp2.o: tp2.c 
	gcc $(CFLAGS) -c tp2.c

myFuncs.o: myFuncs.c myFuncs.h
	gcc $(CFLAGS) -c myFuncs.c

meminfo.o: meminfo.c meminfo.h myFuncs.h
	gcc $(CFLAGS) -c meminfo.c

cpuinfo.o: cpuinfo.c cpuinfo.h myFuncs.h
	gcc $(CFLAGS) -c cpuinfo.c

version.o: version.c version.h myFuncs.h
	gcc $(CFLAGS) -c version.c

clean:
	rm -f *.o tp2