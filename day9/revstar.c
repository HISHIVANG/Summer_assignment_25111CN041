#include <stdio.h>
int main(){
    int i,j;
    int x;
    printf("enter the amount of stars you want in the first row:");
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        for(j=x;j>=i;j--){
            printf("*");}
        printf("\n");}
         return 0;}