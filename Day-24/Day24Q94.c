//Write a program to Compress a string. 
#include <stdio.h>
#include <stdlib.h>
char *compress(char st[]){
    int read = 0;
    int write =0;
    char c='\0';
    int count = 1;
    int size = 20+1;
    char *cps = (char*)malloc(size*sizeof(char));
    while(st[read]!='\0'){
        c=st[read++];
        if(write>=size){
            size*=2;
            cps = (char*)realloc(cps,size*sizeof(char));
        }
        if(st[read]==c){
            count++;
        }
        else{
            cps[write++]=c;
            int start = write;
            while(count>0){
                if(write>=size){
                    size*=2;
                    cps = (char*)realloc(cps,size*sizeof(char));
                }
                cps[write++]='0'+count%10;
                count/=10;
            }
            for(int i = start, j = write - 1; i < j; i++, j--){
                char t = cps[i];
                cps[i] = cps[j];
                cps[j] = t;
            }
            count = 1;
        }
    }
    cps = (char*)realloc(cps,(1+write)*sizeof(char));
    cps[write]='\0';
    return cps;
}
int main(){
    int size = 20 +1;
    char st[size];
    printf("Enter string: ");
    scanf("%s",st);
    //fgets(st,size,stdin);
    char *c = compress(st);
    printf("Compressed = %s",c);
    free(c);
    return 0;
}
