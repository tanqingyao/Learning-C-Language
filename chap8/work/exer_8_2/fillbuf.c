#include "tempio.h"
#include "syscall.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/* 分配并填充输入缓冲区 */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)   /* 还未分配缓冲区 */
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;     /* 不能分配缓冲区 */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
int _flushbuf(int x, FILE *fp){
    return (unsigned char) *fp->ptr++;
}