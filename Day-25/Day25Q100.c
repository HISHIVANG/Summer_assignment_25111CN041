//Write a program to Sort words by length. 
#include <stdio.h>
#include <string.h>
int arrange(int n,int size,char st[n][size]){
    int min;
    char t[size];
    for(int i = 1;i<n;i++){
        min = i-1;
        for(int j = i;j<n;j++){
            if(strlen(st[min])>strlen(st[j])){min = j;}
        }
        if(min!=i-1){
            strcpy(t,st[min]);
            strcpy(st[min],st[i-1]);
            strcpy(st[i-1],t);
        }
    }
    
}
int main(){
    int size = 20 +1;
    int num = 0;
    printf("Enter number of words : ");
    scanf("%d",&num);
    char words[num][size];
    printf("Enter words:\n");
    for(int i = 0;i<num;i++){
        scanf("%s",&words[i]);
    }
    arrange(num,size,words);
    printf("Arranged by length :\n");
    for(int i = 0;i<num;i++){
        printf("%d. %s\n",i+1,words[i]);
    }
    return 0;
}

