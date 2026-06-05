#include <stdio.h>
int main(){
    int i,j;
    char arr[6]= {'A','B','C','D','E'};
    for(i=0;i<=5;i++){
         for(j=0;j<=i-1;j++){
         printf("%c",arr[j]);
        }
         printf("\n");}
         return 0;}