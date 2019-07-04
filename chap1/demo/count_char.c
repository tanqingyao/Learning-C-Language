#include <stdio.h>
/*Unix/Linux 中输入ctrl-D代表EOF*/
int main()
{
	double nc;

	for(nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}
