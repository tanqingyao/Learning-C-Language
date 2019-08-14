#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

#define MAXOP 100

void debug(int n) {
    printf("debug:");
	putchar(n);
	printf("\n");
};

int main()
{
	int type;
	double op2;

	int num;

	while ((type = getop(&num)) != EOF) {
		//printf("begin main while:\n");
		// print_stack();
		switch (type) {
			case NUMBER:
				printf("The value is %d\n", num);
				push(num);			
				break;
			case '+':
				printf("The op is + \n");
				push(pop() + pop());
				break;
			case '*':
				printf("The op is * \n");
				push(pop() * pop());
				break;
			case '-':
				printf("The op is - \n");
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0){
					int temp = (int)pop() % (int)op2;
					push((double) temp);
				}
				else
					printf("error: zero remainder\n");
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %d\n", type);
				break;
		}
		// printf("end main while\n");
	}
	return 0;
}
