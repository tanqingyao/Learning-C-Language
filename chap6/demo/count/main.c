#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
	    if (isalpha(word[0])) {
            // printf("word is :%s\n", word);
		    if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                // printf("n is :%d\n", n);
                // printf("keytab word is :%s\n", keytab[n].word);
			    keytab[n].count++;
            }
        }
    for (n = 0; n < NKEYS; n++)
	    if (keytab[n].count > 0)
		    printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;    
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)		
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}