all: gcc_matrix gcc_matrixClock icc_matrix icc_matrixClock

gcc_matrix: matrix.c
	gcc -O3 matrix.c -o gcc_matrix.o

gcc_matrixClock: matrixClock.c
	gcc -O3 matrixClock.c -o gcc_matrixClock.o

icc_matrix: matrix.c
	icc -fast matrix.c -o icc_matrix.o

icc_matrixClock: matrixClock.c
	icc -fast matrixClock.c -o gcc_matrixClock.o

clean:
	rm -f *_matrix.o
	rm -f *_matrixCLock.o
	rm -f *_matrix.o
	rm -f *_matrixCLock.o

run:
	time ./gcc_matrix.o 512
	time ./gcc_matrix.o 1024
	time ./gcc_matrix.o 1536
	time ./gcc_matrix.o 2048
	time ./icc_matrix.o 512
	time ./icc_matrix.o 1024
	time ./icc_matrix.o 1536
	time ./icc_matrix.o 2048



