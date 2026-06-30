//Write a program to Find column-wise sum
#include <stdio.h>

int main(){
    int n, m;
    printf("Enter number n: ");
    scanf("%d", &n);
    printf("Enter number m: ");
    scanf("%d", &m);
    if(n < 1 || m < 1){
        printf("invalid");
        return 0;
    }
    int arr[n][m];
    int res[m];
    printf("Enter arr:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("<%d,%d> : ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += arr[j][i];
        }
        res[i] = sum;
    }
    for(int i = 0; i < m; i++){
        printf("Sum of Columns %d: %d\n", i+1, res[i]);
    }
    return 0;
}