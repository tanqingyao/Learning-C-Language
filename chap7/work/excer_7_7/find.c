#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
    FILE *fp[argc];
    char *fname[argc];
    int i = 0;
    /*默认输入流stdin */
    int files = argc - 1;
    fp[files] = stdin;
    fname[files] = "stdin";
    while (argc > 1)  /*打开文件，若argc == 1则只剩下待查找字符 */
    {
        fname[i] = *argv;
        if ((fp[i++] = fopen(*argv++, "r")) == NULL)
        {
            printf("cat : can't open %s\n", *argv);
            return 1;
        }
        argc--;
    }

	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
    else    /*在每个输入流中查找 */
    {
        i = 0;
        while (i < files || files == 0) {
            while (fgets(line, MAXLINE, fp[i]) > 0) {
                lineno++;
                if ((strstr(line, *argv) != NULL) != except) {
                    printf("\t%s:\n", fname[i]);
                    if (number)
                        printf("%ld:", lineno);
                    printf("%s", line);
                    found++;
                }
            }
            fclose(fp[i]);
            i++;
            if (files == 0) /*默认stdin只查找一次 */
                break;
        }
    }    
	return found;
}