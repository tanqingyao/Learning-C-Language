#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "calc.h"

#define MAXOP 100

int arg_type(char arg) {
	switch (arg) {
		default:
			if (isdigit(arg))
				return NUMBER;
			return arg;
	}
}

int main(int argc, char *argv[])
{
	int type;
	double op2;
	char s[MAXOP];

	int arg_type(char arg);

	while (--argc > 0) {
		int param = (*++argv)[0];
		type = arg_type(param);
		switch (type) {
			case NUMBER:
				push(atof(*argv));
				break;
			case '+':
				op2 = pop();
				push(pop() + op2);
				break;
			case '*':
				/*instead of type *, type '*' in command line*/
				op2 = pop();
				push(pop() * op2);
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
	}
	printf("\t%.8g\n", pop());
	return 0;
}
