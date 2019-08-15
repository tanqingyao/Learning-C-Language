#include <stdio.h>
#include <string.h>
#include "tnode.h"
struct tnode *talloc(void);
char *strdup_(char *);
struct list *lalloc(void);
void debug(int );

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
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
/*交换两个链表节点 */
void swap(struct list *pre, struct list *p)
{
	char *word;
	int count;
	word = pre->word;
	count = pre->count;
	/*交换 */
	pre->word = p->word;
	pre->count = p->count;
	p->word = word;
	p->count = count;
}
/*将树节点tp插入链表节点lp之后，返回插入节点指针 */
struct list *addlist(struct list *lp, struct tnode *tp)
{
	struct list *p = lalloc();
	p->word = tp->word;
	p->count = tp->count;
	if (lp == NULL) {
		p->next = NULL;
	} else {
		p->next = lp->next;
		lp->next = p;
	}
	return p;
}
/*将二叉树节点加入有序链表 */
struct list *tree2list(struct tnode *tp, struct list *lp)
{
	struct list *p, *pre;

	if (tp == NULL) {
		return lp;
	}
	else if (lp == NULL) {
		lp = addlist(lp, tp);
	} 
	else {
		for (p = lp; p != NULL; p = p->next) {
			pre = p;
			if (p->count < tp->count) //插入该链表节点之前
			{
				swap(addlist(p, tp), p);
				break;
			}
		}
		if (p == NULL)
			addlist(pre, tp);
	}
	tree2list(tp->left, lp);
	tree2list(tp->right, lp);
	return lp;
}

void listprint(struct list *list)
{
	struct list *p;
	for (p = list; p != NULL; p = p->next)
	{
		printf("%4d %s\n", p->count, p->word);
	}
}