#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>

#define MAXLEN 5000
int getline_(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	int begin_time, end_time;
	begin_time = clock();
	while ((len = getline_(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			/*
			 *   replace (p = alloc(len)) with (p = array_lines)
			 */
			return -1;
		}
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			//array_lines = array_lines + len;
		}
	}
	end_time = clock();
	printf("running time is :%d ms\n", end_time - begin_time);
	return nlines;
}

void writelines(char *lineptr[], int nlines, int n)
{
	int relocate = nlines - n;
	while (n-- > 0)
		printf("%s\n", *(relocate + lineptr++));
}

int getline_(char *s, int lim)
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
