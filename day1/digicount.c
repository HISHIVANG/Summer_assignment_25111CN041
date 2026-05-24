#include <stdio.h>
int main(){
int a,i,count=1;
printf("enter the number:");
scanf("%d",&a);
 while(a%10!=1){
   a = a/10;
   count+=1;}
printf("the number of digits in the given number %d",count);
return 0;}