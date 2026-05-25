#include<stdio.h>
int gcd(int a, int b){
    int z = a%b;
    if(z==0){return z;}
    else{return (gcd(b,z));}}
int main(){
    int a,b;
    printf("Enter the larger number");
    scanf("%d",&a);
    printf("Enter the smaller number");
    scanf("%d",&b);
    int c = gcd(a,b);
    printf("gcd is equal to: %d",c);
    return 0;} //galat code hai yeh
    

    