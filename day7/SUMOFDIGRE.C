#include <stdio.h>
int sumD(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumD(n / 10);}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum of digits = %d", sumD(num));
    return 0;}