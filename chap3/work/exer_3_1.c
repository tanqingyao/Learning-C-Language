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
	if(result == -1)
		printf("No value match\n");
	else
		printf("The value is:%d\n", result);
}
int binsearch(int x, int v[],int n)
{
	int low, high, mid;
	int begin_time, end_time;

	low = 0;
	high = n - 1;
	begin_time = clock();
	while (low < high && low + 1 != high) {
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid;
	}
	end_time = clock();

	printf("Running time is : %d ms\n", end_time - begin_time);

	if(v[low] == x)
		return low;
	if(v[high] == x)
		return high;
	return -1;
}
