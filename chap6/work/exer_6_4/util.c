#include <stdlib.h>
#include <string.h>
#include "tnode.h"
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

struct list *lalloc(void)
{
	return (struct list *) malloc(sizeof(struct list));
}