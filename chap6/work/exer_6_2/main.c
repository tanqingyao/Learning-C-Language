#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct arr_tnode *add_arrtree(struct arr_tnode *, char *);
void arr_treeprint(struct arr_tnode *);

int main(int argc, char *argv[])
{
	if (argc == 1) {
		struct tnode *root;
		char word[MAXWORD];

		root = NULL;
		while (getword(word, MAXWORD) != EOF)
			if (isalpha(word[0]))
				root = addtree(root, word);
		treeprint(root);
	} else if (argc == 2 && atoi(argv[1]) == 6) {
		struct arr_tnode *root;
		char word[MAXWORD];

		root = NULL;
		while (getword(word, MAXWORD) != EOF)
			if (isalpha(word[0]))
				root = add_arrtree(root, word);
		arr_treeprint(root);
	} else
	{
		printf("Wrong parameters\n");
	}
	
	return 0;
}
