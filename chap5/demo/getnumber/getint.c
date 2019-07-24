#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		int last_c = c;	/*---excercise 5-1---*/
		c = getch();
		if (!isdigit(c))
			ungetch(last_c);
	}
	for (*pn = 0; isdigit(c); c =getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	//int c1 = getch();
	//int c2 = getch();
	//printf("ungetch char is %d, %d:\n", c1, c2);
	return c;
}
