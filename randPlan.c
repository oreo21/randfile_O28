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
	int arr1[10];
	int i = 0;
	printf("generating random numbers...\n");
	for (i; i < 10; i++){
		arr1[i] = genRand();
		printf("random %d = %d\n", i, arr1[i]);
	}
	printf("\nwriting numbers to file...\n");
	int filedesc = open("numbers.csv", O_CREAT | O_APPEND, 0666);
	int data = write(filedesc, arr1, 40);
	printf("filedesc: %d\n", filedesc);
  	if (filedesc == -1)
  		printf("error: %d - %s\n", errno, strerror(errno));  
  	
	printf("reading numbers from file...\n\n");

}

