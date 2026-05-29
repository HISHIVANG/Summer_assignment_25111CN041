#include<stdio.h>
int main(){
int a,b,c,temp;
printf("enter the first (larger) number:");
scanf("%d",&a);
printf("enter the second (smaller) number:");
scanf("%d",&b);
while(b!=0){
c = a%b;
temp = b;
b = c;
a = temp;}
if(b==0){
    printf("the GCD is %d",temp);}
return 0;}