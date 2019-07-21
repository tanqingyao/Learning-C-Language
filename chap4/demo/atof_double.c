#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int main()
{
	double sum, atof_my(char []);
	char line[MAXLINE];
	int getline_my(char line[], int max);

	sum = 0;
	while (getline_my(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

double atof_my(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for(val == 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

int getline_my(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
