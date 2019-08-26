#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char * argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];
    int begin_time, end_time;

    begin_time = clock();
    if (argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
            
        }
    end_time = clock();

    printf("Running time is : %d ms\n", end_time - begin_time);
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
    
}