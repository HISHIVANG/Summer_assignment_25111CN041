#include <stdio.h>
int main(){
    int i,j;
    char arr[6]= {'A','B','C','D','E'};
    for(i=1;i<=5;i++){
         for (j=1;j<=i;j++){
            printf("%c",arr[i - 1]);}
         printf("\n");}
         return 0;}