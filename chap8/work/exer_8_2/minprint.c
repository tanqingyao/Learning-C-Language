#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define START 0
#define END 1

void ungetch(int);
int getstr(int, char *);

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;

    int ival;
    double dval;

    char format[MAXWORD];
    char *f = format;
    int cond, state;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        state = START;
        while (cond = *++p) {
            switch (cond) {  /*  *p == % 进行下面判断*/
            case 'd':
                state = getstr(cond ,f);

                ival = va_arg(ap, int);
                printf(f, ival);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'f':
                state = getstr(cond ,f);
                
                dval = va_arg(ap, double);
                printf(f, dval);
                break;
            case 's':
                state = getstr(cond ,f);

                sval = va_arg(ap, char *);
                printf(f, sval);
                // for (sval = va_arg(ap, char *); *sval; sval++)
                //     putchar(*sval);
                break;       
            default:
                if (cond == '-' || isdigit(cond) || cond == '.')
                    ungetch(cond);
                else {  //先输出缓存，再输出字符串
                    state = getstr(cond ,f);
                    printf("%s", f);
                }
                break;
            }
            if (state == END)
                break;
        }
    }
    va_end(ap);
}