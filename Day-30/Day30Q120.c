//Write a program to Develop complete mini project using arrays, strings and functions.
//Mini Contact Book Management System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct contact{
    char name[31];
    char phone[16];
    char email[41];
    char address[51];
    int in_use;
} contact;

void eatstdin();
int menu();
void Add_contact(contact **PPcontacts,size_t *Psize);
void Find_contact(contact **PPcontacts,size_t *Psize);
void Remove_contact(contact **PPcontacts, size_t *Psize);
void display_all(contact **PPcontacts, size_t *Psize);
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
    contact *Pcontacts = (contact*)malloc(size*sizeof(contact));
    for(int i =0;i<size;i++){
        Pcontacts[i].in_use = 0;
        strcpy(Pcontacts[i].name,"\0");
        strcpy(Pcontacts[i].phone,"\0");
        strcpy(Pcontacts[i].email,"\0");
        strcpy(Pcontacts[i].address,"\0");
    }
    while(1){
        int c = menu();
        if(c == 1) Add_contact(&Pcontacts,&size);
        else if(c == 2) Find_contact(&Pcontacts,&size);
        else if(c == 3) Remove_contact(&Pcontacts,&size);
        else if(c == 4) display_all(&Pcontacts,&size);
        else if(c == 5) break;
    }
    free(Pcontacts);
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
        printf("Mini Contact Book System\n");
        printf("1. Add Contact\n");
        printf("2. Find Contact\n");
        printf("3. Remove Contact\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Choice: ");
        if(intinput("Enter Choice(1,2,3,4): ",&c)) continue;
        return c;
    }
}
void Add_contact(contact **PPcontacts,size_t *Psize){
    char name[31];
    char phone[16];
    char email[41];
    char address[51];
    printf("\033c");
    if(strinput("Enter Name: ",name,31)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Phone Number: ",phone,16)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Email: ",email,41)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Address: ",address,51)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPcontacts)[i].in_use == 1 &&
            strcmp((*PPcontacts)[i].phone,phone)==0){  
                char c =' ';
                while(chinput("Phone number already exists. Overwrite contact?(y/n)",&c,"yn")!=0);
                if(c=='y'){
                    strcpy((*PPcontacts)[i].name,name);
                    strcpy((*PPcontacts)[i].email,email);
                    strcpy((*PPcontacts)[i].address,address);
                } return;
        }   
    }
    for(int i = 0; i < *Psize; i++){
        if(!(*PPcontacts)[i].in_use){
            strcpy((*PPcontacts)[i].name,name);
            strcpy((*PPcontacts)[i].phone,phone);
            strcpy((*PPcontacts)[i].email,email);
            strcpy((*PPcontacts)[i].address,address);
            (*PPcontacts)[i].in_use = 1;
            break;
        }
    }
    printf("Done.");
    sleep(1);
}
void Find_contact(contact **PPcontacts,size_t *Psize){
    char phone[16];
    printf("\033c");
    if(strinput("Enter Phone Number to search: ",phone,16)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPcontacts)[i].in_use == 1 &&
            strcmp((*PPcontacts)[i].phone,phone)==0){  
                printf("Name: %s\nPhone: %s\nEmail: %s\nAddress: %s\nPress [Enter] to return to the menu...",
                    (*PPcontacts)[i].name,(*PPcontacts)[i].phone,(*PPcontacts)[i].email,(*PPcontacts)[i].address);
                getchar();
                return;
        }   
    }
    printf("Failed.");
    sleep(1);
}
void Remove_contact(contact **PPcontacts, size_t *Psize){
    char phone[16];
    printf("\033c"); // Clear screen
    if (strinput("Enter Phone Number of contact to remove: ", phone, 16)){
        printf("Error\n");
        sleep(1);
        return;
    }
    
    for (size_t i = 0; i < *Psize; i++){
        if ((*PPcontacts)[i].in_use == 1 &&
            strcmp((*PPcontacts)[i].phone, phone) == 0){  
                
                char c = ' ';
                printf("\nContact Found: %s | Phone: %s | Email: %s\n", 
                       (*PPcontacts)[i].name, (*PPcontacts)[i].phone, (*PPcontacts)[i].email);
                
                while (chinput("Are you sure you want to remove this contact? (y/n): ", &c, "yn") != 0);
                if (c == 'y'){
                    (*PPcontacts)[i].in_use = 0;
                    strcpy((*PPcontacts)[i].name, "");
                    strcpy((*PPcontacts)[i].phone, "");
                    strcpy((*PPcontacts)[i].email, "");
                    strcpy((*PPcontacts)[i].address, "");
                    
                    printf("Contact successfully removed.\n");
                } else{
                    printf("Removal canceled.\n");
                }
                sleep(1);
                return;
        }   
    }
    
    printf("Contact not found.\n");
    sleep(1);
}
void display_all(contact **PPcontacts, size_t *Psize){
    printf("\033c");
    printf("====================CURRENT_CONTACT_BOOK====================\n");
    printf("%-4s | %-20s | %-14s | %-25s\n", "No.", "Name", "Phone", "Email");
    printf("-----------------------------------------------------------------------\n");
    
    int count = 0;
    for (size_t i = 0; i < *Psize; i++) {
        if ((*PPcontacts)[i].in_use == 1) {
            count++;
            printf("%-4d | %-20s | %-14s | %-25s\n", 
                   count,
                   (*PPcontacts)[i].name, 
                   (*PPcontacts)[i].phone, 
                   (*PPcontacts)[i].email);
        }
    }
    if (count == 0) {
        printf("               [ Contact book is currently empty ]            \n");
    }
    printf("=========================================================================\n");
    printf("\nPress [Enter] to return to the menu...");
    getchar(); 
}