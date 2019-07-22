#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];
/*
 *---excersie 4-4---begin---
 *
 */
void print_stack(void){
	printf("###print stack:\n");
	for(int i = 0; i < sp; i++)
		printf("The %d is %f\n", i, val[i]);
	printf("###END\n");
}

void print_stack_top(void){
	if (sp > 0)
		printf("The top of stack is %f\n", val[sp - 1]);
        else
                printf("The stack is empty, can't print the top value\n");
}

double copy_stack_top(void){
	if (sp > 0)
		return val[sp - 1];
	else
		printf("The stack is empty, can't copy the top value\n");
}

void swap_stack_top(void){
	double temp;
	if(sp > 1){
		temp = *(val + sp -1);
		*(val + sp -1) = *(val + sp -2);
		*(val + sp -2) = temp;
	} else
		printf("The stack top-2 value is lack, can't swap them.");
}

void clean_stack(void){
	sp = 0;
}

/*
*
* ---excerse 4-4 ---end---
* 
*/

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
