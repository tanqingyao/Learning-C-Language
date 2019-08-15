#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"

#define MAXOP 100
#define LETTER 26

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	char  ch;
	double ltr[LETTER] = {0.0}, val;

	while ((type = getop(s)) != EOF) {
		printf("begin main while:\n");
		//print_stack();
		switch (type) {
			case NUMBER:
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
			/*
			 * ---exercise 4-3 ---
			 */
			case '%':
				op2 = pop();
				if (op2 != 0.0){
					int temp = (int)pop() % (int)op2;
					push((double) temp);
				}
				else
					printf("error: zero remainder\n");
			/*
			 * ---exercise 4-5 ---			 
			 */
			case MATH:
				if (strcmp(s, "sin") == 0)
					push(sin(pop()));
				if (strcmp(s, "exp") == 0)
					push(exp(pop()));
				if (strcmp(s, "pow") == 0) {
					op2 = pop();
					push(pow(pop(), op2));
				}
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			/*--- 4-5 ---*/
			case '\n':
				printf("The calculated result is:\t%.8g\n", pop());
				break;
			/*
			 * --- 4-6 ---
			 */
			case '=':
				if(isupper(var)){
					ltr[var - 'A'] = pop();
					printf("saved the varible.\n");
				}
				else
					printf("Please input uppercase letter~\n");
				break;
			default:
				if (isupper(type))
					push(ltr[type - 'A']);
				else
					printf("error: unknown command %s\n", s);
				break;
			/*--- 4-6 ---*/
		}
		//printf("---begin main while:---\n");
                //print_stack_top();
		//print_stack();
		//double temp_copy = copy_stack_top();
		//printf("The copy value is %f\n", temp_copy);

		//swap_stack_top();
		//print_stack_top();
                //print_stack();

		//clean_stack();
		//print_stack_top();
                //print_stack();

		printf("---end main while------\n");
	}
	return 0;
}
