#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen(__FILE__, "r");
    char c;
    do {
        c = getc(fp);
        putchar(c);
    }while(c != EOF);
    return 0;
}

