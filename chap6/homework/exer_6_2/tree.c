#include <stdio.h>
#include <string.h>
#include "node.h"
struct tnode *talloc(void);
char *strdup_(char *);
struct arr_tnode *arralloc(void);

void debug(int);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup_(w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	// debug(2);
	// printf("the tnode is : %p\n", p);
	if (p != NULL) {
		treeprint(p->left);
		// debug(3);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}


struct arr_tnode *add_arrtree(struct arr_tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = arralloc();
		p->word = strdup_(w);
		p->nodes_in_array = NULL;
		p->left = NULL;
		p->right = NULL;
		//放入数组中
		p->nodes_in_array = addtree(p->nodes_in_array, w);
	} else if ((cond = strncmp(w, p->word, 3)) == 0)	//为了便于测试，这里设置3
		addtree(p->nodes_in_array, w);
	else if (cond < 0)
		p->left = add_arrtree(p->left, w);
	else
		p->right = add_arrtree(p->right, w);
	return p;
}

void arr_treeprint(struct arr_tnode *p)
{
	if (p != NULL) {
		arr_treeprint(p->left);
		printf("Group: \n");
		treeprint(p->nodes_in_array);
		printf("\n");
		arr_treeprint(p->right);
	}
}