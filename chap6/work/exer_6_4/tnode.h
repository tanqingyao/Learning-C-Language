struct tnode {
        char *word;
        int count;
        struct tnode *left;
        struct tnode *right;
};

struct list {
        char *word;
        int count;
        struct list *next;        
};