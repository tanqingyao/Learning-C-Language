#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
int in_list(char *);	/*这里用几个程序中的关键词测试 */

void debug(int i){printf("%d: Running...\n",i);};

int main()
{
	struct tnode *root;
	char word[MAXWORD];

	int number;

	root = NULL;
	while ((number = getword(word, MAXWORD)) != EOF)
		if (isalpha(word[0]) && !in_list(word)) {
			root = addtree(root, word, number);
		}
	treeprint(root);
	return 0;
}
