#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;

	//printf("input the expression:\n");
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (isupper(c)) {	/*check the uppercase*/
		var = c;
		return c;
	}
	if (islower(c)) {	/*check the downcase*/
		i = 0;
		while (islower(s[++i] = c = getch()))
                        ;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return MATH;
	}
	if (!isdigit(c) && c != '.' && c != '-')	/*other char*/
		return c;
	i = 0;
	if (c  == '-')	/* check negtive number*/
		s[++i] = c = getch();
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
