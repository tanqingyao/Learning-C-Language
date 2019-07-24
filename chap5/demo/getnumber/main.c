#include <stdlib.h>
#include <stdio.h>

#define SIZE 100

int main()
{
	int n, array[SIZE], getint(int *);

	int getfloat(double *);
	double array_f[SIZE];

	for (n = 0; n < SIZE && getfloat(&array_f[n]) != EOF; n++)
		printf("The value is: %f\n", array_f[n]);


//	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
//		printf("The value is: %d\n", array[n]);
}
