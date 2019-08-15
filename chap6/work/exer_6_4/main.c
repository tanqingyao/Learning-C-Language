#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct list * tree2list(struct tnode *, struct list *);
void listprint(struct list *);
void debug(int i){printf("%d: Running...\n", i);};

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	struct list *head;

	root = NULL;
	head = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	// treeprint(root);
	head = tree2list(root, head);
	listprint(head);
	return 0;
}
