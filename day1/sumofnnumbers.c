#include <stdio.h>
int main(){
int a,i,sum=0;
printf("enter the nth digit for sum of 'n' numbers:");
scanf("%d",&a);
for(i=0;i<=a;i++){
    sum = sum+i;}
printf("the sum upto nth natural number is : %d", sum);
return 0;}