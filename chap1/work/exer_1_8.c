#include <stdio.h>

int main()
{
	int c, nline, nspace, ntabs;

	nline = 0;
	nspace = 0;
	ntabs = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nline;
		else if (c == ' ')
			++nspace;
		else if (c == '\t')
			++ntabs;
	printf("space: %d, tabs: %d, lines: %d\n", nspace, ntabs, nline);
}
