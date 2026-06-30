//Write a program to Create mini library system.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct book{
    char title[51];
    char author[31];
    int book_id;
    char genre[21];
    int quantity;
    int in_use;
} book;

void eatstdin();
int menu();
void Add_book(book **PPbooks,size_t *Psize);
void Find_book(book **PPbooks,size_t *Psize);
void Remove_book(book **PPbooks, size_t *Psize);
void display_all(book **PPbooks, size_t *Psize);
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
    book *Pbooks = (book*)malloc(size*sizeof(book));
    for(int i =0;i<size;i++){
        Pbooks[i].in_use = 0;
        strcpy(Pbooks[i].title,"\0");
        strcpy(Pbooks[i].author,"\0");
        Pbooks[i].book_id = 0;
        strcpy(Pbooks[i].genre,"\0");
        Pbooks[i].quantity = 0;
    }
    while(1){
        int c = menu();
        if(c == 1) Add_book(&Pbooks,&size);
        else if(c == 2) Find_book(&Pbooks,&size);
        else if(c == 3) Remove_book(&Pbooks,&size);
        else if(c == 4) display_all(&Pbooks,&size);
        else if(c == 5) break;
    }
    free(Pbooks);
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
        printf("Mini Library System\n");
        printf("1. Add Book\n");
        printf("2. Find Book\n");
        printf("3. Remove Book\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Choice: ");
        if(intinput("Enter Choice(1,2,3,4): ",&c)) continue;
        return c;
    }
}
void Add_book(book **PPbooks,size_t *Psize){
    char title[51];
    char author[31];
    int book_id;
    char genre[21];
    int quantity;
    printf("\033c");
    if(strinput("Enter Title: ",title,51)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Author: ",author,31)){
        printf("Error");
        sleep(1);
        return;
    }
    if(intinput("Enter Book ID: ",&book_id)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Genre: ",genre,21)){
        printf("Error");
        sleep(1);
        return;
    }
    if(intinput("Enter Quantity (copies): ",&quantity)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPbooks)[i].in_use == 1 &&
            (*PPbooks)[i].book_id==book_id){  
                char c =' ';
                while(chinput("Book ID already exists. Add copies to existing entry?(y/n)",&c,"yn")!=0);
                if(c=='y'){
                    (*PPbooks)[i].quantity+=quantity;
                } return;
        }   
    }
    for(int i = 0; i < *Psize; i++){
        if(!(*PPbooks)[i].in_use){
            strcpy((*PPbooks)[i].title,title);
            strcpy((*PPbooks)[i].author,author);
            (*PPbooks)[i].book_id=book_id;
            strcpy((*PPbooks)[i].genre,genre);
            (*PPbooks)[i].quantity=quantity;
            (*PPbooks)[i].in_use = 1;
            break;
        }
    }
    printf("Done.");
    sleep(1);
}
void Find_book(book **PPbooks,size_t *Psize){
    int book_id;
    printf("\033c");
    if(intinput("Enter Book ID to search: ",&book_id)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPbooks)[i].in_use == 1 &&
            (*PPbooks)[i].book_id==book_id){  
                printf("Title: %s\nAuthor: %s\nGenre: %s\nCopies Available: %d\nPress [Enter] to return to the menu...",
                    (*PPbooks)[i].title,(*PPbooks)[i].author,(*PPbooks)[i].genre,(*PPbooks)[i].quantity);
                getchar();
                return;
        }   
    }
    printf("Failed.");
    sleep(1);
}
void Remove_book(book **PPbooks, size_t *Psize){
    int book_id;
    printf("\033c"); // Clear screen
    if (intinput("Enter Book ID to remove: ", &book_id)){
        printf("Error\n");
        sleep(1);
        return;
    }
    
    for (size_t i = 0; i < *Psize; i++){
        if ((*PPbooks)[i].in_use == 1 &&
            (*PPbooks)[i].book_id == book_id){  
                
                char c = ' ';
                printf("\nBook Found: %s | Author: %s | Copies: %d\n", 
                       (*PPbooks)[i].title, (*PPbooks)[i].author, (*PPbooks)[i].quantity);
                
                while (chinput("Are you sure you want to remove this book? (y/n): ", &c, "yn") != 0);
                if (c == 'y'){
                    (*PPbooks)[i].in_use = 0;
                    (*PPbooks)[i].book_id = 0;
                    (*PPbooks)[i].quantity = 0;
                    strcpy((*PPbooks)[i].title, "");
                    strcpy((*PPbooks)[i].author, "");
                    strcpy((*PPbooks)[i].genre, "");
                    
                    printf("Book successfully removed.\n");
                } else{
                    printf("Removal canceled.\n");
                }
                sleep(1);
                return;
        }   
    }
    
    printf("Book not found.\n");
    sleep(1);
}
void display_all(book **PPbooks, size_t *Psize){
    printf("\033c");
    printf("====================CURRENT_LIBRARY_CATALOG====================\n");
    printf("%-4s | %-25s | %-20s | %-8s | %-12s | %6s\n", "No.", "Title", "Author", "Book ID", "Genre", "Copies");
    printf("-----------------------------------------------------------------------------\n");
    
    int count = 0;
    for (size_t i = 0; i < *Psize; i++) {
        if ((*PPbooks)[i].in_use == 1) {
            count++;
            printf("%-4d | %-25s | %-20s | %-8d | %-12s | %6d\n", 
                   count,
                   (*PPbooks)[i].title, 
                   (*PPbooks)[i].author, 
                   (*PPbooks)[i].book_id, 
                   (*PPbooks)[i].genre,
                   (*PPbooks)[i].quantity);
        }
    }
    if (count == 0) {
        printf("               [ Library catalog is currently empty ]            \n");
    }
    printf("=================================================================================\n");
    printf("\nPress [Enter] to return to the menu...");
    getchar(); 
}