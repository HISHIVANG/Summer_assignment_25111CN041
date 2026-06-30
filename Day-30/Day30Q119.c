//Write a program to Create mini employee management system.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct employee{
    char name[31];
    int emp_id;
    char department[21];
    char designation[21];
    double salary;
    int in_use;
} employee;

void eatstdin();
int menu();
void Add_employee(employee **PPemployees,size_t *Psize);
void Find_employee(employee **PPemployees,size_t *Psize);
void Remove_employee(employee **PPemployees, size_t *Psize);
void display_all(employee **PPemployees, size_t *Psize);
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
    employee *Pemployees = (employee*)malloc(size*sizeof(employee));
    for(int i =0;i<size;i++){
        Pemployees[i].in_use = 0;
        strcpy(Pemployees[i].name,"\0");
        Pemployees[i].emp_id = 0;
        strcpy(Pemployees[i].department,"\0");
        strcpy(Pemployees[i].designation,"\0");
        Pemployees[i].salary = 0;
    }
    while(1){
        int c = menu();
        if(c == 1) Add_employee(&Pemployees,&size);
        else if(c == 2) Find_employee(&Pemployees,&size);
        else if(c == 3) Remove_employee(&Pemployees,&size);
        else if(c == 4) display_all(&Pemployees,&size);
        else if(c == 5) break;
    }
    free(Pemployees);
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
        printf("Mini Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Find Employee\n");
        printf("3. Remove Employee\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Choice: ");
        if(intinput("Enter Choice(1,2,3,4): ",&c)) continue;
        return c;
    }
}
void Add_employee(employee **PPemployees,size_t *Psize){
    char name[31];
    int emp_id;
    char department[21];
    char designation[21];
    double salary;
    printf("\033c");
    if(strinput("Enter Name: ",name,31)){
        printf("Error");
        sleep(1);
        return;
    }
    if(intinput("Enter Employee ID: ",&emp_id)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Department: ",department,21)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Designation: ",designation,21)){
        printf("Error");
        sleep(1);
        return;
    }
    if(doubleinput("Enter Salary: ",&salary)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPemployees)[i].in_use == 1 &&
            (*PPemployees)[i].emp_id==emp_id){  
                char c =' ';
                while(chinput("Employee ID already exists. Overwrite record?(y/n)",&c,"yn")!=0);
                if(c=='y'){
                    strcpy((*PPemployees)[i].name,name);
                    strcpy((*PPemployees)[i].department,department);
                    strcpy((*PPemployees)[i].designation,designation);
                    (*PPemployees)[i].salary=salary;
                } return;
        }   
    }
    for(int i = 0; i < *Psize; i++){
        if(!(*PPemployees)[i].in_use){
            strcpy((*PPemployees)[i].name,name);
            (*PPemployees)[i].emp_id=emp_id;
            strcpy((*PPemployees)[i].department,department);
            strcpy((*PPemployees)[i].designation,designation);
            (*PPemployees)[i].salary=salary;
            (*PPemployees)[i].in_use = 1;
            break;
        }
    }
    printf("Done.");
    sleep(1);
}
void Find_employee(employee **PPemployees,size_t *Psize){
    int emp_id;
    printf("\033c");
    if(intinput("Enter Employee ID to search: ",&emp_id)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPemployees)[i].in_use == 1 &&
            (*PPemployees)[i].emp_id==emp_id){  
                printf("Name: %s\nDepartment: %s\nDesignation: %s\nSalary: %.2f\nPress [Enter] to return to the menu...",
                    (*PPemployees)[i].name,(*PPemployees)[i].department,(*PPemployees)[i].designation,(*PPemployees)[i].salary);
                getchar();
                return;
        }   
    }
    printf("Failed.");
    sleep(1);
}
void Remove_employee(employee **PPemployees, size_t *Psize){
    int emp_id;
    printf("\033c"); // Clear screen
    if (intinput("Enter Employee ID to remove: ", &emp_id)){
        printf("Error\n");
        sleep(1);
        return;
    }
    
    for (size_t i = 0; i < *Psize; i++){
        if ((*PPemployees)[i].in_use == 1 &&
            (*PPemployees)[i].emp_id == emp_id){  
                
                char c = ' ';
                printf("\nEmployee Found: %s | Department: %s | Designation: %s | Salary: %.2f\n", 
                       (*PPemployees)[i].name, (*PPemployees)[i].department, 
                       (*PPemployees)[i].designation, (*PPemployees)[i].salary);
                
                while (chinput("Are you sure you want to remove this employee? (y/n): ", &c, "yn") != 0);
                if (c == 'y'){
                    (*PPemployees)[i].in_use = 0;
                    (*PPemployees)[i].emp_id = 0;
                    (*PPemployees)[i].salary = 0.0;
                    strcpy((*PPemployees)[i].name, "");
                    strcpy((*PPemployees)[i].department, "");
                    strcpy((*PPemployees)[i].designation, "");
                    
                    printf("Employee successfully removed.\n");
                } else{
                    printf("Removal canceled.\n");
                }
                sleep(1);
                return;
        }   
    }
    
    printf("Employee not found.\n");
    sleep(1);
}
void display_all(employee **PPemployees, size_t *Psize){
    printf("\033c");
    printf("====================CURRENT_EMPLOYEE_RECORDS====================\n");
    printf("%-4s | %-20s | %-7s | %-15s | %-15s | %10s\n", "No.", "Name", "Emp ID", "Department", "Designation", "Salary");
    printf("----------------------------------------------------------------------------\n");
    
    int count = 0;
    for (size_t i = 0; i < *Psize; i++) {
        if ((*PPemployees)[i].in_use == 1) {
            count++;
            printf("%-4d | %-20s | %-7d | %-15s | %-15s | $%9.2f\n", 
                   count,
                   (*PPemployees)[i].name, 
                   (*PPemployees)[i].emp_id, 
                   (*PPemployees)[i].department, 
                   (*PPemployees)[i].designation,
                   (*PPemployees)[i].salary);
        }
    }
    if (count == 0) {
        printf("               [ No employee records found ]            \n");
    }
    printf("==================================================================================\n");
    printf("\nPress [Enter] to return to the menu...");
    getchar(); 
}