#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define LINESTORE 20000

char *lineptr[MAXLINES];
/*excercise 5-7*/
//static char array_lines[LINESTORE];

int readlines(char *lineptr[], int nlines);
/*excercise 5-7*/
//int readlines(char *lineptr[], int nlines, char array_lines[]);

void writelines(char *lineptr[], int nlines, int n);
/*excercise 5-8 添加第三个参数*/
//void qsort(char *lineptr[], int left, int right);

int main(int argc, char *argv[])
{
	int nlines;
	int num;

	char c = argv[1][0];
	if (argc != 2 || (c != '-')) {
		printf("Usage: tail -n\n");
		return 0;
	}
	else {		
		num = -1 * atoi(argv[1]);
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		/*for 5-7 add readlines fun with third param*/
//		qsort(lineptr, 0, nlines - 1);
		printf("---sort result---\n");
		writelines(lineptr, nlines, num);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
