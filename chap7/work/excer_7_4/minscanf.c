#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;

    int *ival;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            // putchar(*p);
            continue;
        }
        switch (*++p) {  /*  *p == % 进行下面判断*/
        case 'd':
            ival = va_arg(ap, int *);
            scanf("%d", ival);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf("%s", sval);
            // for (sval = va_arg(ap, char *); *sval; sval++)
            //     putchar(*sval);
            break;
        default:
            // putchar(*p);
            break;
        }
    }
    va_end(ap);
}