#include <stdio.h>
#include <string.h>
#include "tnode.h"
struct tnode *talloc(void);
char *strdup_(char *);

struct list *lalloc(void);
struct list *addlist(struct list *p, int n);
void debug(int );
struct tnode *addtree(struct tnode *p, char *w, int n)
{
	int cond;
	struct list *plist;

	if (p == NULL) {
		p = talloc();
		p->word = strdup_(w);
		p->count = 1;
		// 新建链表节点，加入链表
		p->line_list = NULL;
		p->line_list = addlist(p->line_list, n);
		p->left = NULL;
		p->right = NULL;

	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
		/*分配行链表节点，加入链表 */
		p->line_list = addlist(p->line_list, n);
	}
	else if (cond < 0)
		p->left = addtree(p->left, w, n);
	else
		p->right = addtree(p->right, w, n);


	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s :\t", p->count, p->word);
		for (int i = 0; i < p->count; i++, p->line_list = p->line_list->next)
			printf("%d,\t",p->line_list->num);
		printf("\n");
		treeprint(p->right);
	}
}

/*新分配一个节点（num=n）,加入链表p中，返回链表指针 */
struct list *addlist(struct list *p, int n)
{
	if (p == NULL) {
		p = lalloc();
		p->num = n;
		p->next = NULL;
	} else
		p->next = addlist(p->next, n);
	return p;
}