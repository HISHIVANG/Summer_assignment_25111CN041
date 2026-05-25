#include<stdio.h>
int main(){
    int a,c,pr=1;
    printf("Enter a number to check if its prime:");
    scanf("%d",&a);
    for(int i=2;i<a;i++){
        c = a%i;
        if(c==0){pr=0;
            break;}}
    if(pr==0){printf("%d is not a prime number",a);}
        else{printf("%d is a prime number",a);}
    return 0;}