//Write a program to Find longest word. 
#include <stdio.h>
int main(){
    int size = 40 +1;
    char st[size];
    char ts[size];
    printf("Enter st: ");
    //scanf("%s",st);
    fgets(st,size,stdin);
    int n=0,wordsize =0,maxsize=0;
    while(st[n]!='\n' && st[n]!='\0'){
        if(st[n]==' '){
            if(wordsize>maxsize){
                maxsize=wordsize;
                for(int j =n-wordsize,k=0;j<n;j++,k++){
                    ts[k]= st[j];
                }
                ts[wordsize]='\0';
            }
            wordsize=0;
        }
        else{
            wordsize++;
        }
        n++;
    }
    if(wordsize>maxsize){
        maxsize=wordsize;
        for(int j =n-wordsize,k=0;j<n;j++,k++){
            ts[k]= st[j];
        }
        ts[wordsize]='\0';
    }
    printf("Longest word = %s",ts);
    return 0;
    
}
