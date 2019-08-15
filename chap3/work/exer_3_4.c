#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define SIZE 1000

void itoa(int n, char s[]);

char *strrev(char *str)
{
	char *p1, *p2;

	if (! str || ! *str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

int main()
{
	char output[SIZE];
	itoa(-2147483648,output);

	for(int i = 0; output[i] != '\0'; i++)
		putchar(output[i]);
	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;

	if((sign = n) < 0){
		n += 1;
		n = -n;
	}
	i = 0;

	do {
		s[i] = n % 10 + '0';
		i++;
	} while ((n /= 10) > 0);
	if (sign < 0){
		s[i++] = '-';
	        s[0] += 1;
	}
	s[i] = '\0';
	//reverse(s);
	strrev(s);
}
