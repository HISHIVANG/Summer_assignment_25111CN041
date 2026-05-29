#include<stdio.h>
int main(){
int a,b,c,temp;
int A,B;
printf("enter the first (larger) number:");
scanf("%d",&a);
printf("enter the second (smaller) number:");
scanf("%d",&b);
A=a;
B=b;
while(b!=0){
c = a%b;
temp = b;
b = c;
a = temp;}
if(b==0){
 int LM=(A*B)/temp;
 printf("the LCM of the given numbers are: %d" ,LM);}
return 0;}