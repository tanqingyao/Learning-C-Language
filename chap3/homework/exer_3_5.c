#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define SIZE 1000

void itob(int n, char s[], int b);

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

	itob(320000, output, 16);

	for(int i = 0; output[i] != '\0'; i++)
		putchar(output[i]);
	return 0;
}

void itob(int n, char s[], int b)
{
	int i, sign;

	if((sign = n) < 0){
		n++;
		n = -n;
	}
	i = 0;

	do {
		if(n % b < 10)
			s[i] = n % b + '0';
		else
			s[i] = n % b + 'a';
		i++;
	} while ((n /= b) > 0);
	if (sign < 0){
		s[i++] = '-';
	        s[0] += 1;
	}
	s[i] = '\0';
	//reverse(s);
	strrev(s);
}
