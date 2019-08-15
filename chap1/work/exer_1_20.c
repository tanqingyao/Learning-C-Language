#include <stdio.h>
#define MAXLINE 1000

#define DETAB 4

int getline_(char line[], int max);

int main()
{
	char line[MAXLINE];
	
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
