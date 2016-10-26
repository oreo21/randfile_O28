#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int genRand(){
	int filedesc = open("../../../../dev/random", O_CREAT, 0666);
	int randInt[1];
	int data = read(filedesc, randInt, 4);
	return randInt[0];
}

void main(){
	umask(0);
	int arr1[10];
	int arr2[10];
	int i = 0;
	printf("generating random numbers...\n");
	for (i; i < 10; i++){
		arr1[i] = genRand();
		printf("random %d = %d\n", i, arr1[i]);
	}
	printf("\nwriting numbers to file...\n");
	/*
	int filedescW = open("numbers.txt", O_CREAT | O_RDWR, 0666);
	int dataW = write(filedescW, arr1, 40);
	close(filedescW);
	printf("filedescW: %d\n", filedescW);
  	if (filedescW == -1)
  		printf("error: %d - %s\n", errno, strerror(errno)); 
  	*/ 
  	//printf("reading numbers from file...\n\n");
  	//int filedescR = open("numbers.txt", O_RDONLY, 0666);
  	//int dataR = read(filedescR, arr2, 40);
  	//printf("data = %d\n", arr2[2]);
}