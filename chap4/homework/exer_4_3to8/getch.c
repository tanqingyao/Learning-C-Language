#include <stdio.h>

#define BUFSIZE 100

/*
 *--- excercise 4-8
 *
 * #define BUFSIZE 1
 */

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
/*
 * excercise 4-7
 */
void ungets(char s[])
{
	int l = strlen(s);
	if (l > 0)
		ungetch(s[--l]);
}

