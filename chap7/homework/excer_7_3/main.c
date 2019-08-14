void minprintf(char *fmt, ...);

int main(){
    minprintf("Testing: %1.2d, %1.2f, %-15.10s\n", 1, 1.0, "Hello, world!");
    return 0;
}