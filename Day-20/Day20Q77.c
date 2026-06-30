//Write a program to Multiply matrices
#include <stdio.h>
#include <stdlib.h>
void Mul(int n,int m,int u,int v,int arr1[n][m],int arr2[u][v],int res[n][v]){
    if(m!=u){
        printf("invalid");
        exit(1);
    }
    int sum=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<v;j++){
            for(int k = 0;k<m;k++){
                sum+=arr1[i][k]*arr2[k][j];
            }
            res[i][j]=sum;
            sum=0;
        }
    }
}
int main(){
    int n,m,u,v;
    printf("Enter number n: ");
    scanf("%d",&n);
    printf("Enter number m: ");
    scanf("%d",&m);
    printf("Enter number u: ");
    scanf("%d",&u);
    printf("Enter number v: ");
    scanf("%d",&v);
    if(n<1||m<1||u<1||v<1){
        printf("invalid");
        return 0;
    }
    int arr1[n][m],arr2[u][v],res[n][v];
    printf("Enter arr1:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("<%d,%d> : ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter arr2:\n");
    for(int i = 0;i<u;i++){
        for(int j = 0;j<v;j++){
            printf("<%d,%d> : ",i+1,j+1);
            scanf("%d",&arr2[i][j]);
        }
    }
    Mul(n,m,u,v,arr1,arr2,res);
    printf("Mul =\n");
    for(int i = 0;i<n;i++){
        printf("{");
        for(int j = 0;j<v;j++){
            if(j>0){printf(",");}
            printf("%d",res[i][j]);
        }
        printf("}\n");
    }
    return 0;
}