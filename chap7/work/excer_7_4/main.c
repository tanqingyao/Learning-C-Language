#include <stdio.h>
void minscanf(char *fmt, ...);

int main(){
    int day, year;
    char monthname[20];
    minscanf("%d %s %d", &day, monthname, &year);
    printf("day is %d, month is %s, year is %d\n", day, monthname, year);
    return 0;
}