#include <stdio.h>
int main(){
    int i,j;
    int x;
    printf("enter the number you want in the first row last position:");
    scanf("%d",&x);
    for(i=x;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("%d",j);}
        printf("\n");}
         return 0;}