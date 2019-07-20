#include <stdio.h>
#include <time.h>

#define LENGTH 1000000

int binsearch(int x,int v[],int n);

int main()
{
	int num[LENGTH];
	int result;

	for(int i = 0; i < LENGTH; i++)
	{
		num[i] = 2*i;
	}
	
	result = binsearch(500001, num, LENGTH);
	printf("The value is:%d\n", result);
}
int binsearch(int x, int v[],int n)
{
	int low, high, mid;
	int begin_time, end_time;

	low = 0;
	high = n - 1;
	begin_time = clock();
	while (low <= high) {
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	end_time = clock();

	printf("Running time is : %d ms", end_time - begin_time);

	return -1;
}
