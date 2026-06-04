#include <stdio.h>
int fact(int a){
    if(a == 0 || a == 1){
        return 1;}
    return a * fact(a - 1);}
int main(){
    int a;
    printf("Enter a number to generate its factorial: ");
    scanf("%d", &a);
    int b = fact(a);
    printf("The factorial of %d is %d\n", a, b);
    return 0;
}