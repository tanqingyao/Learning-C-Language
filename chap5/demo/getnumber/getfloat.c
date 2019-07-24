#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
	double power;

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
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 10.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}
	*pn *= sign / power;
	if (c != EOF)
		ungetch(c);
	return c;
}
