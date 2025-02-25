all:
	@ gcc -c main.c -o main.o
	@ gcc -c scheduler.c -o scheduler.o
	@ gcc scheduler.o main.o -o scheduler
	@ ./scheduler

clean:
	@ rm main.o scheduler.o scheduler