#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sys/syscall.h"
#include <fcntl.h>
int main(int argc, char * argv[])
{
    FILE *fp;
    void filecopy(int, int);
    char *prog = argv[0];
    int begin_time, end_time;

    begin_time = clock();
    if (argc == 1)
        filecopy(0, 1);
    else
        while (--argc > 0)
        {
            int fd;
            // fd = open(*++argv, O_RDONLY, 0);
            // fp = fopen(*++argv, "r")
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
            {
                printf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fd, 1);
                // fclose(fp);
                close(fd);
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

void filecopy(int ifd, int ofd)
{
    char buf[BUFSIZ];
    int n;
    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        write(1, buf, n);
    return 0;   
}