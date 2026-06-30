//Write a program to Create menu-driven array operations system.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int menu(int **arr,size_t *size);
void setsize(int **arr,size_t *size);
void entervalues(int **arr,size_t *size);
void display(int **arr,size_t *size);
void setvalue(int **arr,size_t *size);
void give_sum(int **arr,size_t *size);
void replace(int **arr,size_t *size);
void flush();
void hold();
int main(){
    size_t size = 10;
    int *arr = (int*)calloc(size,sizeof(int));
    while(1){
        int c = menu(&arr,&size);
        if(c == 1) setsize(&arr,&size);
        else if(c == 2) entervalues(&arr,&size);
        else if(c == 3) setvalue(&arr,&size);
        else if(c == 4) give_sum(&arr,&size);
        else if(c == 5) replace(&arr,&size);
        else if(c == 6) break;
    }
    free(arr);
    return 0;
}
void flush(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void hold(){
    int c;
    printf("\nEnter any key to continue. ");
    scanf(" %c",&c);
}
void setsize(int **arr,size_t *size){
    size_t i;
    printf("\033cEnter new size: ");
    if(scanf(" %zu",&i)!=1){
        printf("Error");
        sleep(1);
        return;
    }
    int *temp = realloc(*arr,i*sizeof(int));
    if(temp == NULL){
        printf("Error");
        sleep(1);
        return;
    }
    *arr = temp;
    *size = i;
}
void entervalues(int **arr,size_t *size){
    int i = 0;
    while (1){
        printf("\033c");
        display(arr,size);
        printf("%d. ",i+1);
        scanf(" %d",&(*arr)[i++]);
        if(i==*size) break;
    }
    
}
void setvalue(int **arr,size_t *size){
    int i=0;
    int ele = 0;
    printf("\033c");
    display(arr,size);
    printf("Enter position : ");
    if(scanf(" %d",&i)!=1){
        printf("Error");
        sleep(1);
        return;
    };
    if(i<1||i>*size){
        printf("Exiting...");
        sleep(1);
        return;
    }
    printf("%d. ",i);
    scanf(" %d",&(*arr)[i-1]);
}
void replace(int **arr,size_t *size){
    int i=0;
    int j=0;
    printf("\033c");
    display(arr,size);
    printf("Enter position i: ");
    if(scanf(" %d",&i)!=1){
        printf("Error");
        sleep(1);
        return;
    };
    if(i<1||i>*size){
        printf("Exiting...");
        sleep(1);
        return;
    }
    printf("Enter position j: ");
    if(scanf(" %d",&j)!=1){
        printf("Error");
        sleep(1);
        return;
    };
    if(j<1||j>*size){
        printf("Exiting...");
        sleep(1);
        return;
    }
    if((i--)==(j--)) return;
    int t = (*arr)[i]; 
    printf("\033c");
    display(arr,size);
    (*arr)[i] = (*arr)[j];
    (*arr)[j] = t;
    printf("\033c");
    display(arr,size);
    sleep(1);
}
void give_sum(int **arr,size_t *size){
    printf("\033c");
    display(arr,size);
    long long sum =0;
    for(size_t i = 0;i<*size;i++){
        sum+=(*arr)[i];
    }
    printf("Sum = %lld",sum);
    hold();
}
void display(int **arr,size_t *size){
    printf("Arr = {");
    for(size_t i = 0;i<*size;i++){
        if(i>0) printf(",");
        printf("%d",(*arr)[i]);
    }printf("}\n");
}
int menu(int **arr,size_t *size){
    int c;
    
    while(1){
        printf("\033c");
        display(arr,size);
        printf("Array Operator\n");
        printf("1. Set size\n");
        printf("2. Enter new values\n");
        printf("3. Set Element\n");
        printf("4. Give sum\n");
        printf("5. Replace elements\n");
        printf("6. Exit\n");
        printf("Choice: ");

        if(scanf("%d", &c) != 1){
            flush();
            continue;
        }

        flush();
        return c;
    }
}