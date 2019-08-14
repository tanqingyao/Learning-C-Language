struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};


#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];