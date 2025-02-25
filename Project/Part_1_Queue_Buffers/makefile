all:
	@ gcc -Wall -Wextra -c main.c -o main.o
	@ gcc -Wall -Wextra -c queue.c -o queue.o
	@ gcc -Wall -Wextra main.o queue.o -o queue
	@ ./queue

clean:
	@ rm main.o queue.o queue