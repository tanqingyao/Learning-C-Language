#define NUMBER '0'
#define MATH '1'

char var;

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

/*
 *for exercise 4-4
 */
void print_stack(void);
void print_stack_top(void);
double copy_stack_top(void);
void swap_stack_top(void);
void clean_stack(void);

/*
 *for exercise 4-7
 */
void ungets(char []);



