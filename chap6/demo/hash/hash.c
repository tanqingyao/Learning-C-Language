#include <stdio.h>
#include "hash.h"

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name == strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
/*exercise6-5 删除链表中节点
 *区分待删除节点为头节点还是普通节点，普通节点需找到前继节点修改链表
 */
struct nlist *undef(char *name, char *defn)
{
	struct nlist *np, *pre;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/*没找到 */
		return -1;
	} else {	/*找到前继节点，删除 */
		hashval = hash(name);
		pre = hashtab[hashval];
		while (pre->next != np)
			pre = pre->next;

		if (pre == hashtab[hashval])
			hashtab[hashval] = NULL;
		else
			pre->next = np->next;
		free((void *) np->defn);
		free((void *) np->name);
		free((void *) np);

		return 0;
	}
}