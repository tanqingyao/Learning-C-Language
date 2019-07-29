
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

    char check[2];

	while (isspace(c = getch()))    /*跳过空格 */
		;
    /*
    exercise 6-1
     */
    if (c == '"')   /*跳过字符串常量 */
        while ((c = getch()) != '"')
            ;
    if (c == '/') {   /*跳过两种注释 */
        switch (c = getch()) {
            case '/':
                while ((c = getch()) != '\n')
                    ;
                break;
            case '*':

                check[0] = getch();
                check[1] = getch();
                while (strcmp("*/", check)) {
                    if (check[0] == EOF || check[1] == EOF) {
                        printf("Please end with: \"*/\"");
                        break;
                    }
                    check[0] = check[1];
                    check[1] = getch();
                }
                break;
            default:
                return c;
                break;
        }
    }
    if (c == '#')   /*跳过预处理器控制指令 */
        while ((c = getch()) != '\n')
            ;
    /*
    ---------------
     */
	if (c != EOF)   /*存入*w */
		*w++ = c;
	if (!isalpha(c)) {  /*不是字母开头 */
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {  /*变量名中能有下划线   && *w != '_' */
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
