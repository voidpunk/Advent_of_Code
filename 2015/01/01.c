#include <stdio.h>

int main (void) {

    const char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");

    int open = 0, closed = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '(') {
            open++;
            }
        else if (ch == ')') {
            closed++;
            }
    }

    int res = open - closed;
    printf("%u\n", (unsigned)(res<0)?-res:res);
    
    fclose(fp);
    return 0;
}