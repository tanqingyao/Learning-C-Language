#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right, int (*comp)(void *, void *), int r);
int numcmp(char *, char *);
int strcmp(char *, char *);

extern unsigned int flag;
extern unsigned int dic;

int main(int argc, char *argv[])
{
	int nlines, c;
	int numeric = 0;
	int reverse = 1;
	flag = 0;
	dic = 0;

//	if (argc > 1 && strcmp(argv[1], "-n") == 0)
//		numer = 1;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = -1;
					break;
				case 'f':
					flag = 1;
					break;
				case 'd':
					dic = 1;
					break;
				default:
					printf("illegal option! %c\n", c);
					argc = 0;
					break;
			}
	if (argc != 0) {
		printf("Usage: sort -r -n\n");
		return 0;
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort_((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse);
		printf("---sort result---\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
