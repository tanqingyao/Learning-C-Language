#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, char * argv[])
{
    FILE *fp1, *fp2;
    // void filecopy(FILE *, FILE *);
    char line1[MAXLINE], line2[MAXLINE];

    if (argc != 3)
        printf("Usage: diff {file1} {file2}\n");
    else
    {
        if ((fp1 = fopen(argv[1], "r")) == NULL)
        {
            printf("cat : can't open %s\n", argv[1]);
            return 1;
        }
        else if ((fp2 = fopen(argv[2], "r")) == NULL)
        {
            printf("cat : can't open %s\n", argv[2]);
            return 1;
        }
        else
        {
            while (fgets(line1, MAXLINE, fp1) && fgets(line2, MAXLINE, fp2))
                if (strcmp(line1, line2)) {
                    printf("The diffrence are\n%s : %s\n%s : %s\n", argv[1], line1, argv[2], line2);
                    break;
                }
            fclose(fp1);
            fclose(fp2);
        }
    }
    return 0;
}