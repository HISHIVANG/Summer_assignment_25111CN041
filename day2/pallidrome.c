#include <stdio.h>
int main(){
int a,rev=0;
int rem=0;
printf("enter the number:");
scanf("%d",&a);
int temp = a;
while(a > 0){
   rem=a%10;
   rev=rev*10+rem;
    a=a/10;}
    if(temp == rev){
        printf("the number %d is a pallidrome number",temp);}
    else{printf("the given number %d isn't pallindrome",temp);}
    return 0;
    else{printf("the given number %d isn't pallindrome",temp);}
    return 0;}
