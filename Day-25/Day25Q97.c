//Write a program to Merge two sorted arrays
#include <stdio.h>
void Merge(int n,int m,int st[n],int ts[m],int merge[n+m]){
    int read1 = 0;
    int read2 = 0;
    for(int write = 0;write<n+m;write++){
        if(read1==n && read2!=m){
            merge[write]=ts[read2++];
        }
        else if(read2==m && read1!=n){
            merge[write]=st[read1++];
        }
        else if((st[read1]<ts[read2])){
            merge[write]=st[read1++];
        }
        else{
            merge[write]=ts[read2++];
        }
    }
}
int main(){
    int n,m;
    printf("Enter number n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("%d. ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter number m: ");
    scanf("%d",&m);
    int arr2[m];
    for(int i=0;i<m;i++){
        printf("%d. ",i+1);
        scanf("%d",&arr2[i]);
    }
    int merge[n+m];
    Merge(n,m,arr,arr2,merge);
    printf("Merged array = ");
    for(int i=0;i<n+m;i++){
        printf("%d ",merge[i]);
    }
    return 0;
}
