//Write a program to Count vowels and consonants
int in(char c,char list[]){
    char t;
    int i = -1;
    while((t=list[++i])!='\0'){
        if(t==c) return 1;
    }
    return 0;
}
int countvowel(char string[]){
    int n=0,c=0;
    char vowels[] = "aeiouAEIOU";
    while(string[n]!='\0'){
        if(in(string[n],vowels)){
            c++;
        }
        n++;
    }
    return c;
}
int countcons(char string[]){
    int n=0,c=0;
    char cons[] = "qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM";
    while(string[n]!='\0'){
        if(in(string[n],cons)){
            c++;
        }
        n++;
    }
    return c;
}
#include <stdio.h>
int main(){
    char st[21];
    printf("Enter string: ");
    //scanf("%s",st);
    fgets(st,21,stdin);
    printf("vowels = %d\nconsonants = %d",countvowel(st),countcons(st));
    return 0;
}