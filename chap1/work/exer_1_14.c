#include<stdio.h>

#define OUT 0
#define IN 1

/*统计各个数字，空白符及其其他字符出现的次数*/
// words[0]储存字符数量，wrods[1~8]储存单词长度为1~8的单词数，words[9]储存长度大于8的单词

int main()
{
	int c, i, nwhite, nother, length;
	int ndigit[10], words[10], cha[128];

	int state;

	nwhite = nother = 0;
	length = 0;
	state = OUT;

	for(i = 0; i < 10; ++i){
		ndigit[i] = 0;
		words[i] = 0;
	}
	for(i = 0; i < 128; ++i)
		cha[i] = 0;
	while((c = getchar()) != EOF){
		//cout char
		if(c < '0' || c > '9')
			if(c < 'a' || c > 'z')
				if(c <= 'A' || c >= 'Z')
					++cha[c];
		//cout words
		if(c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			if(length < 9)
				++words[length];
			else
				++words[9];
			length = 0;
		}
		else if(state == OUT)
			state = IN;
		else if(state == IN)
			++length;
		//cout digits
		if(c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if(c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}

	//print digits
	printf("digits =");
	for(i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
	
	//print words table
	printf("words[i]: \n");
	for(i = 1; i < 10; ++i)
		printf("%2d, ", words[i]);
	printf("\n");
	/*find max*/
	int max = 0;
	for(i = 1; i < 10; ++i){
		if(words[i] > max)
			max = words[i];
	}
	int row, col;
	for(row = 0; row < max; ++row){
		for(col = 1; col < 10; ++col)
			if(words[col] > row)
				printf(" #  ");
			else
				printf("    ");
		printf("\n");
	}

	//print char table
	for(i = 0; i < 128; ++i)
		if(cha[i] != 0){
			putchar(i);
			printf(": %d\n", cha[i]);
		}
}
