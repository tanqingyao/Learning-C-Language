#include <stdio.h>

#define SIZE 1000

void escape(char s[], char t[]);
int main()
{
	int c, i;

	char input[SIZE], output[SIZE];

	i = 0;
	while ((c = getchar()) != EOF) {
		input[i++] = c;
	}

	escape(output, input);

	for(i = 0; output[i] != '\0'; i++ )
		putchar(output[i]);
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;

	i = 0;
	j = 0;
	while (t[j] != '\0') {
		switch (t[i]) {
                        case '\t':
				s[j++] = '\\';
				s[j++] = 't';
                                break;
                        case '\b':
				s[j++] == '\\';
				s[j++] == 'b';
                                break;
                        case '\r':
				s[j++] == '\\';
				s[j++] == 'r';
                                break;
                        case '\n':
				s[j++] == '\\';
				s[j++] == 'n';
                                break;
                        default:
				s[j++] = t[i];
                                break;
                }
		i++;
	}
	s[j] = '\0';
}
