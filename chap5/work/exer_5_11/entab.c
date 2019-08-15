#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline_(char line[], int max);
int DETAB = 8;

int main(int argc, char *argv[])
{
	char line[MAXLINE];

	if (argc != 2)
		printf("Usage: detab number!\n");
	else
		DETAB = atoi(argv[1]);

	while (getline_(line, MAXLINE) > 0)
		printf("%s\n", line);

	return 0;
}
int getline_(char s[], int lim)
{
	int c, i, num;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		if (c == '\t') {
			for (num = DETAB - i % DETAB; num > 0; num--)	//计算到剩下的空格数
				s[i++] = ' ';
		} else
			s[i++] = c;
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
