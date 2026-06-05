#include <stdio.h>
int main(){
    int i,j;
    int x;
    printf("enter the amount of stars you want in the last row:");
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        for(j=1;j<=i;j++){
            printf("*");}
        printf("\n");}
         return 0;}