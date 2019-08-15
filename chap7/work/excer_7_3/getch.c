#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : 0;
}

void ungetch(int c)
{
    // printf("ungetch...\n");
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
/*将%开头，sign结尾的字符串保存到s中 */
int getstr(int sign,char *s)
{
    char *t = buf;
    *s++ = '%';
    for( ; bufp > 0; bufp--)
        *s++ = *t++;
    *s++ = sign;
    *s = '\0';
    return 1;
}