//Write a program to Create student record management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct employee{
    char name[21];
    int empid;
    char department[21];
    float salary;
    int active;
} emp;

emp emplist[30];

void flush(){
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}

int find_empid(int empid){
    for(int i=0;i<30;i++){
        if(emplist[i].active && emplist[i].empid==empid)
            return i;
    }
    return -1;
}

int create_employee(int empid,char name[],char department[],float salary){
    for(int i=0;i<30;i++){
        if(!emplist[i].active){
            emplist[i].empid=empid;
            strcpy(emplist[i].name,name);
            strcpy(emplist[i].department,department);
            emplist[i].salary=salary;
            emplist[i].active=1;
            return i;
        }
    }
    return -1;
}

void show_employee(int id){
    system("cls");

    if(id<0 || id>=30 || !emplist[id].active){
        printf("Employee Not Found\n");
        sleep(1);
        return;
    }

    printf("---------------------------------------------------------------\n");
    printf("Name       : %s\n",emplist[id].name);
    printf("Employee ID: %d\n",emplist[id].empid);
    printf("Department : %s\n",emplist[id].department);
    printf("Salary     : %.2f\n",emplist[id].salary);
    printf("---------------------------------------------------------------\n");

    getchar();
}

void add_employee(){
    char name[21];
    char department[21];
    int empid;
    float salary;

    system("cls");

    printf("Enter Employee Name : ");
    fgets(name,21,stdin);
    name[strcspn(name,"\n")] = '\0';

    printf("Enter Employee ID   : ");
    scanf("%d",&empid);
    flush();

    if(find_empid(empid)!=-1){
        printf("Employee already exists.\n");
        sleep(2);
        return;
    }

    printf("Enter Department    : ");
    fgets(department,21,stdin);
    department[strcspn(department,"\n")] = '\0';

    printf("Enter Salary        : ");
    scanf("%f",&salary);
    flush();

    if(create_employee(empid,name,department,salary)==-1){
        printf("Database Full\n");
    }
    else{
        printf("Employee Added Successfully\n");
    }

    sleep(2);
}

void remove_employee(){
    int empid;

    system("cls");

    printf("Enter Employee ID to remove: ");
    scanf("%d",&empid);
    flush();

    int id=find_empid(empid);

    if(id==-1){
        printf("Employee Not Found\n");
    }
    else{
        emplist[id].active=0;
        printf("Employee Removed Successfully\n");
    }

    sleep(2);
}

void show_by_name(){
    char name[21];

    system("cls");

    printf("Enter Employee Name: ");
    fgets(name,21,stdin);
    name[strcspn(name,"\n")] = '\0';

    system("cls");

    printf("S.No | Name                 | ID      | Department      | Salary\n");

    int count=1;

    for(int i=0;i<30;i++){
        if(emplist[i].active &&
           strcmp(name,emplist[i].name)==0){

            printf("%-4d | %-20s | %-7d | %-15s | %.2f\n",
                   count++,
                   emplist[i].name,
                   emplist[i].empid,
                   emplist[i].department,
                   emplist[i].salary);
        }
    }

    getchar();
}

void show_by_department(){
    char department[21];

    system("cls");

    printf("Enter Department: ");
    fgets(department,21,stdin);
    department[strcspn(department,"\n")] = '\0';

    system("cls");

    printf("S.No | Name                 | ID      | Department      | Salary\n");

    int count=1;

    for(int i=0;i<30;i++){
        if(emplist[i].active &&
           strcmp(department,emplist[i].department)==0){

            printf("%-4d | %-20s | %-7d | %-15s | %.2f\n",
                   count++,
                   emplist[i].name,
                   emplist[i].empid,
                   emplist[i].department,
                   emplist[i].salary);
        }
    }

    getchar();
}

void show_by_id(){
    int empid;

    system("cls");

    printf("Enter Employee ID: ");
    scanf("%d",&empid);
    flush();

    show_employee(find_empid(empid));
}

void show_all(){
    system("cls");

    printf("S.No | Name                 | ID      | Department      | Salary\n");

    int count=1;

    for(int i=0;i<30;i++){
        if(emplist[i].active){

            printf("%-4d | %-20s | %-7d | %-15s | %.2f\n",
                   count++,
                   emplist[i].name,
                   emplist[i].empid,
                   emplist[i].department,
                   emplist[i].salary);
        }
    }

    getchar();
}

int find_employee_menu(){
    int choice;

    while(1){
        system("cls");

        printf("Find Employee By\n");
        printf("1. Name\n");
        printf("2. Employee ID\n");
        printf("3. Department\n");
        printf("Choice: ");

        if(scanf("%d",&choice)!=1){
            flush();
            continue;
        }

        flush();
        return choice;
    }
}

int menu(){
    int choice;

    while(1){
        system("cls");

        printf("========== Employee Management System ==========\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Find Employee\n");
        printf("4. Show All Employees\n");
        printf("5. Exit\n");
        printf("Choice: ");

        if(scanf("%d",&choice)!=1){
            flush();
            continue;
        }

        flush();
        return choice;
    }
}

int main(){

    for(int i=0;i<30;i++)
        emplist[i].active=0;

    while(1){

        int choice=menu();

        if(choice==1){
            add_employee();
        }
        else if(choice==2){
            remove_employee();
        }
        else if(choice==3){

            choice=find_employee_menu();

            if(choice==1)
                show_by_name();
            else if(choice==2)
                show_by_id();
            else if(choice==3)
                show_by_department();
        }
        else if(choice==4){
            show_all();
        }
        else if(choice==5){
            break;
        }
    }

    return 0;
}