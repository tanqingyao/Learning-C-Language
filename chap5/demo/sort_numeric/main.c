#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

int main(int argc, char *argv[])
{
	int nlines;
	int numer = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numer = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort_((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numer ? numcmp : strcmp));
		printf("---sort result---\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
