#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

unsigned int flag;
unsigned int dic;

void swap(void *v[], int i,int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] =temp;
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int strcmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	/*
	* exercise 5-16
	*/

	while (dic && (ispunct(*s) || ispunct(*t)))
		if (ispunct(*s))
		    s++;
		else
			t++;
	if (flag == 1) {	/*5-15 不考虑字母大小写*/
		int sbase = 0, tbase = 0;
  		if (isupper(*s))
    			sbase = 32;
		if (isupper(*t))
                        tbase = 32;
		return (*s + sbase) - (*t + tbase);
	}
	else
		return *s - *t;
}

void qsort_(void *v[], int left, int right, int (*comp)(void *, void *), int r)
{
	int i, last;

	void swap(void *v[], int, int);

	if (left >= right)
		return ;
    swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (r * (*comp)(v[i], v[left]) < 0)	/*添加反号实现逆序*/
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort_(v, left, last - 1, comp, r);
	qsort_(v, last + 1, right, comp, r);
}
