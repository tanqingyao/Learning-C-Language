#include <string.h>
#include <stdlib.h>

void swap(void *v[], int i,int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] =temp;
}

int numcmp(const char *s1, const char *s2)
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

void qsort_(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right)
		return ;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort_(v, left, last - 1, comp);
	qsort_(v, last + 1, right, comp);
}
