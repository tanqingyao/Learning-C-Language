#include <stdio.h>

#define IN 1
#define OUT 0

/*统计输入的行数，单词数，字符数*/

int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}
		else if(state == OUT){
			state = IN;
			++nw;
			putchar('\n');
		}
		if(c != '\n')
			putchar(c);
	}
}
