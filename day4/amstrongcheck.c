#include <stdio.h>
int main(){
    int n, a=0,d=1,e;
printf("enter the number to check if its amstrong:");
scanf("%d",&n);
if(d!=0){
d=n%10;
a=a+(d*d*d);
n=n%10;}
else{e=(n/10);
    a=a+(e*e*e);}
if(a==n){printf("the entered number is an amstrong number!");}
else{printf("the number is not an amstrong number");}
return 0;
}
