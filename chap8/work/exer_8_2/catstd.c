// #include <stdio.h>
#include "tempio.h"
// #include <stdlib.h>
#include <time.h>

FILE *fopen(char *name, char *mode);
void minprintf(char *fmt, ...);

FILE _iob[OPEN_MAX] = {     /* stdin, stdout, stderr */
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 },
};

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
            fp = fopen(*++argv, "r");
            // if ((fp = fopen(*++argv, "r")) == NULL)
            // {
            //     // printf(stderr, "%s: can't open %s\n", prog, *argv);
            //     minprintf("%s: can't open %s\n", prog, *argv);
            //     exit(1);
            // }
            // else
            // {
            //     filecopy(fp, stdout);
            //     fclose(fp);
            // }
            filecopy(fp, stdout);
        }
    end_time = clock();

    // printf("Running time is : %d ms\n", end_time - begin_time);
    minprintf("Running time is : %d ms\n", end_time - begin_time);
    // if (ferror(stdout)) {
    //     // fprintf(stderr, "%s: error writing stdout\n", prog);
    //     minprintf("%s: error writing stdout\n", prog);
    //     exit(2);
    // }
    // exit(0);
    return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
    
}