#include <stdio.h>
int main(){
int a,prod=1;
int rem=0;
printf("enter the number:");
scanf("%d",&a);
while(a!=0){
   rem=a%10;
   prod=prod*rem;
    a=a/10;}
if(prod!=0){
    printf("the product of the digits in the given number is : %d", prod);}
   return 0;
}