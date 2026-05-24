#include <stdio.h>
int main(){
int a,i,fact=1;
printf("enter the digit to obtain factorial:");
scanf("%d",&a);
for(i=1;i<=a;i++){
    fact = fact*i;}
printf("the factorial of %d is equal to %d",a,fact);
return 0;}