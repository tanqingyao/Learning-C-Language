struct tnode {
        char *word;
        int count;
        struct tnode *left;
        struct tnode *right;
};

/*
 *练习6-2 分组打印，每组前6个字符相同，结构arrnode存放同属于一个组的节点
 */
struct arr_tnode {
        char *word;
        struct tnode *nodes_in_array;
        struct arr_tnode *left;
        struct arr_tnode *right;
};
