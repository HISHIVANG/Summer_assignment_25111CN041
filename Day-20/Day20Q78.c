//Write a program to Check symmetric matrix. 
#include <stdio.h>
int is_symmetric(int n ,int arr[n][n]){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i][j]!=arr[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n;
    printf("Enter number n: ");
    scanf("%d",&n);
    if(n<1){
        printf("invalid");
        return 0;
    }
    int arr[n][n];
    printf("Enter arr:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("<%d,%d> : ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i = 0;i<n;i++){
        printf("{");
        for(int j = 0;j<n;j++){
            if(j>0){printf(",");}
            printf("%d",arr[i][j]);
        }
        printf("}\n");
    }
    if(is_symmetric(n,arr)){
        printf("Symmetric");
    }
    else{
        printf("Not Symmetric");
    }
    return 0;
}