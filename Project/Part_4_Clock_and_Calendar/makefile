all:
	@ gcc -c main.c -o main.o
	@ gcc -c scheduler.c -o scheduler.o
	@ gcc -c Rtcc.c -o Rtcc.o
	@ gcc scheduler.o main.o Rtcc.o -o scheduler
	@ ./scheduler