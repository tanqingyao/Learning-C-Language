#include <stdio.h>
#include <ctype.h>
#include <string.h>

int num = 1;    //  记录行号
/* 在每个有getch()函数的地方加入行号检查，用num更新行号 */

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

    char check[2];  //  检查注释/**/

	while (isspace(c = getch()))    /*跳过空格,换页，换行，回车等 */
		if (c == '\n')
            num++;

	if (c != EOF)   /*存入*w */
		*w++ = c;
	if (!isalpha(c)) {  /*不是字母开头 */
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {  /*变量名中能有下划线   && *w != '_' */
			ungetch(*w);    //这里会把换行符放回，不用进行检查
			break;
		}
	*w = '\0';
	return num;
}
