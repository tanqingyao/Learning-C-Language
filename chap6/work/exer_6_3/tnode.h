struct tnode {
        char *word;
        int count;
        struct list *line_list;
        struct tnode *left;
        struct tnode *right;
};

/* 行号链表 */

struct list {
        int num;
        struct list *next;
};
