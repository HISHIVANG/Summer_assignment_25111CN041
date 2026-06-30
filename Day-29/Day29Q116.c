//Write a program to Create inventory management system
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct item{
    char name[21];
    double price;
    int quantity;
    char shelf[4]; //A01
    int in_use;
} item;

void eatstdin();
int menu();
void Add_item(item **PPitems,size_t *Psize);
void Find_item(item **PPitems,size_t *Psize);
void Remove_item(item **PPitems, size_t *Psize);
void display_all(item **PPitems, size_t *Psize);
int chinput(char command[],char *p,char choices[]);
int intinarr(int num, int arr[],size_t size);
int charinstr(char ch, char str[]);
int intinput(char command[],int *p);
int strinput(char command[],char *p,int size);
int floatinput(char command[],float *p);
int doubleinput(char command[],double *p);
void cleanfgets(char *p);

//MAIN--------------------------------
int main(){
    size_t size = 10;
    item *Pitems = (item*)malloc(size*sizeof(item));
    for(int i =0;i<size;i++){
        Pitems[i].in_use = 0;
        strcpy(Pitems[i].name,"\0");
        Pitems[i].quantity = 0;
        Pitems[i].price = 0;
        strcpy(Pitems[i].shelf,"\0");
    }
    while(1){
        int c = menu();
        if(c == 1) Add_item(&Pitems,&size);
        else if(c == 2) Find_item(&Pitems,&size);
        else if(c == 3) Remove_item(&Pitems,&size);
        else if(c == 4) display_all(&Pitems,&size);
        else if(c == 5) break;
    }
    free(Pitems);
    return 0;
}//MAIN------------------------------

void eatstdin(){
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}
int intinarr(int num, int arr[],size_t size){
    for(size_t i = 0; i<size; i++)
        if(arr[i] == num) return 1;
    return 0;
}
int charinstr(char ch, char str[]){
    for(size_t i = 0; str[i] != '\0'; i++)
        if(str[i] == ch) return 1;
    return 0;
}
int floatinput(char command[],float *p){
    if(p==NULL) return -1;
    printf("%s",command);
    if(scanf(" %f",p)!=1){
        eatstdin();
        return 1;
    }   
    eatstdin(); 
    return 0;
}
int doubleinput(char command[],double *p){
    if(p==NULL) return -1;
    printf("%s",command);
    if(scanf(" %lf",p)!=1){
        eatstdin();
        return 1;
    }   
    eatstdin(); 
    return 0;
}
int strinput(char command[],char *p,int size){
    if(p==NULL) return -1;
    printf("%s",command);
    fgets(p,size,stdin);
    cleanfgets(p);
    return 0;
}
void cleanfgets(char *p){
    size_t l = strlen(p);
    if(l<1) return;
    if(p[l-1]=='\n') p[l-1]='\0';
}
int chinput(char command[],char *p,char choices[]){
    if(p==NULL) return -1;
    printf("%s",command);int e;
    if((e = scanf(" %c",p))==0){
        eatstdin();
        return 1;
    } 
    if(e==-1){
        return -1;
    } 
    if(!charinstr(*p,choices)){
        eatstdin();
        return 2;
    } 
    eatstdin(); 
    return 0;
}
int intinput(char command[],int *p){
    if(p==NULL) return -1;
    printf("%s",command);
    if(scanf(" %d",p)!=1){
        eatstdin();
        return 1;
    }   
    eatstdin(); 
    return 0;
}
int menu(){
    int c;
    while(1){
        printf("\033c");
        printf("Inventory Management\n");
        printf("1. Add Item\n");
        printf("2. Find Item\n");
        printf("3. Remove Item\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Choice: ");
        if(intinput("Enter Choice(1,2,3,4): ",&c)) continue;
        return c;
    }
}
void Add_item(item **PPitems,size_t *Psize){
    char name[21];
    double price;
    int quantity;
    char shelf[4];
    printf("\033c");
    if(strinput("Enter Name of item: ",name,21)){
        printf("Error");
        sleep(1);
        return;
    }
    if(doubleinput("Enter price: ",&price)){
        printf("Error");
        sleep(1);
        return;
    }
    if(intinput("Enter Quantity: ",&quantity)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter shelf id: ",shelf,4)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPitems)[i].in_use == 1 &&
            strcmp((*PPitems)[i].name,name)==0 &&
            (*PPitems)[i].price==price &&
            strcmp((*PPitems)[i].shelf,shelf)==0){  
                char c =' ';
                while(chinput("Item Already exist. continue?(y/n)",&c,"yn")!=0);
                if(c=='y'){
                    (*PPitems)[i].quantity+=quantity;
                } return;
        }   
    }
    for(int i = 0; i < *Psize; i++){
        if(!(*PPitems)[i].in_use){
            strcpy((*PPitems)[i].name,name);
            (*PPitems)[i].price=price;
            (*PPitems)[i].quantity=quantity;
            strcpy((*PPitems)[i].shelf,shelf);
            (*PPitems)[i].in_use = 1;
            break;
        }
    }
    printf("Done.");
    sleep(1);
}
void Find_item(item **PPitems,size_t *Psize){
    char name[21];
    double price;
    int quantity;
    char shelf[4];
    printf("\033c");
    if(strinput("Enter Name of item: ",name,21)){
        printf("Error");
        sleep(1);
        return;
    }
    if(doubleinput("Enter price: ",&price)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPitems)[i].in_use == 1 &&
            strcmp((*PPitems)[i].name,name)==0 &&
            (*PPitems)[i].price==price){  
                printf("Found at shelf: %s\nPress [Enter] to return to the menu...",(*PPitems)[i].shelf);
                fgetchar();
                return;
        }   
    }
    printf("Failed.");
    sleep(1);
}
void Remove_item(item **PPitems, size_t *Psize){
    char name[21];
    double price;
    printf("\033c"); // Clear screen
    if (strinput("Enter Name of item to remove: ", name, 21)){
        printf("Error\n");
        sleep(1);
        return;
    }
    if (doubleinput("Enter price: ", &price)){
        printf("Error\n");
        sleep(1);
        return;
    }
    
    for (size_t i = 0; i < *Psize; i++){
        if ((*PPitems)[i].in_use == 1 &&
            strcmp((*PPitems)[i].name, name) == 0 &&
            (*PPitems)[i].price == price){  
                
                char c = ' ';
                printf("\nItem Found: %s | Price: %.2f | Quantity: %d\n", 
                       (*PPitems)[i].name, (*PPitems)[i].price, (*PPitems)[i].quantity);
                
                while (chinput("Are you sure you want to remove this item? (y/n): ", &c, "yn") != 0);
                if (c == 'y'){
                    (*PPitems)[i].in_use = 0;
                    (*PPitems)[i].quantity = 0;
                    (*PPitems)[i].price = 0.0;
                    strcpy((*PPitems)[i].name, "");
                    strcpy((*PPitems)[i].shelf, "");
                    
                    printf("Item successfully removed.\n");
                } else{
                    printf("Removal canceled.\n");
                }
                sleep(1);
                return;
        }   
    }
    
    printf("Item not found.\n");
    sleep(1);
}
void display_all(item **PPitems, size_t *Psize){
    printf("\033c");
    printf("====================CURRENT_INVENTORY====================\n");
    printf("%-4s | %-20s | %10s | %8s | %-6s\n", "No.", "Name", "Price", "Quantity", "Shelf");
    printf("-----------------------------------------------------------\n");
    
    int count = 0;
    for (size_t i = 0; i < *Psize; i++) {
        if ((*PPitems)[i].in_use == 1) {
            count++;
            printf("%-4d | %-20s | $%9.2f | %8d | %-6s\n", 
                   count,
                   (*PPitems)[i].name, 
                   (*PPitems)[i].price, 
                   (*PPitems)[i].quantity, 
                   (*PPitems)[i].shelf);
        }
    }
    if (count == 0) {
        printf("               [ Inventory is currently empty ]            \n");
    }
    printf("===========================================================\n");
    printf("\nPress [Enter] to return to the menu...");
    getchar(); 
}