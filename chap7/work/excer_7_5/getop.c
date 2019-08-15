#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(int *i)
{
	char s;
	int cond;

	cond = scanf("%c", &s);
	if (cond == EOF)
		return EOF;
	else
	{
		while (s == ' ') { //跳过空格
			scanf("%c", &s);
		}
		if (!isdigit(s))
			return s;
		else
		{
			ungetc(s, stdin);	//写回文件流
		}
	}

	if (scanf("%d", i))	/*此时会忽略空格 */
	{
		return NUMBER;
	}
}
