#include <stdio.h>
int main() {
    int i, j, star;
    for(i=1; i<=5; i++) {
        for(j=1; j<=5-i; j++)
            printf(" ");
        for(star=1; star<=2*i-1; star++)
            printf("*");
        printf("\n");
    }
    return 0;
}