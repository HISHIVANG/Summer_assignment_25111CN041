//Write a program to Find maximum occurring character
#include <stdio.h>

char maxfreqchar(char st[]){
    int n =0;
    int t[256];
    for(int i = 0;i<256;i++){
        t[i]=0;
    }
    while (st[n]!='\0'){
        t[st[n]]+=1;
        n++;
    }
    int max=0;
    for(int i = 1;i<256;i++){
        if(i=='\n') continue;
        if(t[i]>t[max]){
            max=i;
        }
    }
    return max;
}
int main(){
    int size = 20 +1;
    char st[size],c;
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    c = maxfreqchar(st);
    if(c==' '){
        printf("Maximum occurring character: Space");
    }
    else{
        printf("Maximum occurring character: %c",c);
    }
    return 0;
}
