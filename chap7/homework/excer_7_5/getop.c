#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(int *i)
{
	// int i, c;

	// while ((s[0] = c = getch()) == ' ' || c == '\t')
	// 	;
	// s[1] = '\0';
	// if (!isdigit(c) && c != '.')
	// 	return c;
	// i = 0;
	// if (isdigit(c))
	// 	while (isdigit(s[++i] = c = getch()))
	// 		;
	// if(c == '.')
	// 	while (isdigit(s[++i] = c = getch()))
	// 		;
	// s[i] = '\0';
	// if (c != EOF)
	// 	ungetch(c);
	// return NUMBER;
	char s;
	int cond;

	cond = scanf("%c", &s);
	if (cond == EOF)
		return EOF;
	else
	{
		while (s == ' ') { //跳过空格
			// printf("one \n");
			scanf("%c", &s);
			// printf("sign1 is: %c\n", s);
		}
		if (s == '\n')
			return '\n';
		else
		{
			// printf("sign2 is: %c\n", s);
			ungetc(s, stdin);	//写回文件流
		}
	}

	// ungetc(s, stdin);
	if (scanf("%d", i))	/*此时会忽略空格 */
	{
		return NUMBER;
	}
	if (scanf("%c", &s))
	{
		return s;
	}
}
