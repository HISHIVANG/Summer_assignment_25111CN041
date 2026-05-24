#include <stdio.h>
int main(){
int a,rev=0;
int rem=0;
printf("enter the number:");
scanf("%d",&a);
while(a > 0){
   rem=a%10;
   rev=rev*10+rem;
    a=a/10;}
if(rev!=0){printf("the reverse of the given number %d is : %d",a,rev);}
  else{printf("the reverse of the number is %d ,a");}
   return 0;}