#include <stdlib.h>
#include <string.h>
#include "node.h"
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s) +  1);
	if (p != NULL)
		strcpy(p,s);
	return p;
}

struct arr_tnode *arralloc(void)
{
	return (struct arr_tnode *) malloc(sizeof(struct arr_tnode));
}