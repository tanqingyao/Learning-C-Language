#include <stdio.h>
#define MAXLINE 1000

#define DETAB 8

int getline_(char line[], int max);

int main()
{
	char line[MAXLINE];
	
	while (getline_(line, MAXLINE) > 0)
		printf("%s\n", line);
	return 0;
}
int getline_(char s[], int lim)
{
	int c, i, j, k;
	i = j = k = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		if (c == ' ') {
	    		if (j > 0) {
				//    上一个字符也是空格。 将第一个空格位置填入\t	
				s[k++] = '\t';
				//    将字符位置调整到\t后。
				i = k;			
				//    清空空格计数器。
				j = 0;
	    		} else {
				//    保留第一个空格的索引。 
			       	k = i;               
			       	s[i++] = c;           
			   	j++;            
			}
        }
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
