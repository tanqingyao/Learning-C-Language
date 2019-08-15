#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int getline_(char line[], int max);
/*默认情况，从第0列开始，每隔8列停止*/
int COL = 0;
int DETAB = 8;

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	char num, c;
	while (--argc > 0) {
		c = (*++argv)[0];
		if (c == '-') {
			num = (*argv)[1];
			COL = num - '0';
		}
		if (c == '+') {
			num = (*argv)[1];
			DETAB = num - '0';
		}
	}
	if (argc != 0)
		printf("Usage:entab -m +n\n");

	while (getline_(line, MAXLINE) > 0)
		printf("%s\n", line);

	return 0;
}
int getline_(char s[], int lim)
{
	int c, i, num;
	int detab = DETAB;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		if (c == '\t') {
			if (i > COL)
				DETAB = detab;
			else
				DETAB = 8;
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
