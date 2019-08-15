#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
/*在字符串数组v[]中，二分查找字符x，若找到返回1，否则返回0 */
int binsearch(char *x, char *v[],int n)
{
	int low, high, mid, cond;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(x, v[mid])) == 0){
			printf("Find:%s\n", v[mid]);
			return 1;
		}
		else if(cond < 0)
			high = mid - 1;
		else if(cond > 0)
			low = mid + 1;
	}
	return 0;
}
int in_list(char *w)
{
	char *words[] = {"EOF", "MAXWORD", "NULL", "if", "void", "words"};

	int length = sizeof(words) / sizeof(char *);

	return binsearch(w, words, length);
}