#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
/*文件指针 */
typedef struct _iobuf {
    int cnt;    /* 剩余字符数 */
    char *ptr;  /* 下一个字符位置 */
    char *base; /* 缓冲区的位置 */
    int flag;   /* 文件访问模式 */
    int fd;     /* 文件描述符 */
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    _READ   = 01,
    _WRITE  = 02,
    _UNBUF  = 04,
    _EOF    = 010,
    _ERR    = 020
};

int _fillbuf(FILE *);       /* 填充缓冲区,重新初始化结构 */
int _flushbuf(int, FILE *); /* 缓冲区满, */

#define foef(p)     (((p)->flag & _EOF) != 0)
#define ferror(p)   (((p)->flag & _EOF) != 0)
#define fileno(p)   ((p)->fd)   /* 文件描述符 */
/* 从文件p的缓冲区中取出字符 */
#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
/* 将字符x放入文件p的缓冲区中 */
#define putc(x,p)   (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)