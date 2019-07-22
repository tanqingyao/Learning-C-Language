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
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		//printf("begin main while:\n");
		//print_stack();
		switch (type) {
			case NUMBER:
				//printf("The value is %f\n", atof(s));
				push(atof(s));			
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
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
				printf("error: unknown command %s\n", s);
				break;
		}
		//printf("end main while\n");
	}
	return 0;
}
