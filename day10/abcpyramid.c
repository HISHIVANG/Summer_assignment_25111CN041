#include <stdio.h>
int main() {
    int i, j;
    char arr[6] = {'A','B','C','D','E'};
    for(i = 1; i <= 4; i++){
        for(j = 0; j <= 4 - i; j++)
            printf(" ");
        for(j = 0; j <= i; j++)
            printf("%c", arr[j]);
        for(j = i - 1; j >= 0; j--)
            printf("%c", arr[j]);
        printf("\n");
    }
    return 0;
}

