#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define LINESTORE 20000

char *lineptr[MAXLINES];
/*excercise 5-7*/
//static char array_lines[LINESTORE];

int readlines(char *lineptr[], int nlines);
/*excercise 5-7*/
//int readlines(char *lineptr[], int nlines, char array_lines[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		/*for 5-7 add readlines fun with third param*/
		qsort(lineptr, 0, nlines - 1);
		printf("---sort result---\n");
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
