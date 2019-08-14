#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;
    
    if (argc == 1) {
        if (strcmp(argv[0], "./tolower") == 0)
            while ((c = getchar()) != EOF)
                putchar(tolower(c));
        else if (strcmp(argv[0], "./toupper") == 0)
            while ((c = getchar()) != EOF)
                putchar(toupper(c));
        else
        {
            printf("Usage: tolower/toupper <{yourfile}");
        }           
    } else
    {
        printf("Wrong parameters!");
    }
    
    return 0;
}