#include <stdio.h>
int main(){
int a,sum=0;
printf("enter the number:");
scanf("%d",&a);
while(a!=0){
    a = a/10;
    sum = sum+a;}
printf("sum of the digits in %d is equal to : %d",sum);
return 0;}