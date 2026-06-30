//Write a program to Check anagram strings.
#include <stdio.h>

int anagram(char st[],char ts[]){
    int n =0;
    int t[256];
    for(int i = 0;i<256;i++){
        t[i]=0;
    }
    while (st[n]!='\0'){
        t[st[n]]+=1;
        n++;
    }
    n =0;
    while (ts[n]!='\0'){
        t[ts[n]]-=1;
        n++;
    }
    for(int i = 0;i<256;i++){
        if(i=='\n') continue;
        if(t[i]!=0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int size = 20 +1;
    char st[size],c;
    char ts[size];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    printf("Enter string: ");
    fgets(ts,size,stdin);
    if(anagram(st,ts))
        printf("Anagram");
    else
        printf("Not anagram");
    return 0;
}
