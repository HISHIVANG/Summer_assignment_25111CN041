//Write a program to Sort names alphabetically
#include <stdio.h>
#include <string.h>
int arrange(int n,int size,char st[n][size]){
    int min;
    char t[size];
    for(int i = 1;i<n;i++){
        min = i-1;
        for(int j = i;j<n;j++){
            if((strcmp(st[min],st[j])+1)/2){min = j;}
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
    printf("Enter number of students : ");
    scanf("%d",&num);
    char names[num][size];
    printf("Enter first names of students:\n");
    for(int i = 0;i<num;i++){
        scanf("%s",&names[i]);
    }
    arrange(num,size,names);
    printf("Arranged :\n");
    for(int i = 0;i<num;i++){
        printf("%d. %s\n",i+1,names[i]);
    }
    return 0;
}

