//Write a program to Create student record system using arrays and strings.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct student{
    char name[31];
    int roll_no;
    char course[21];
    float marks;
    char grade;
    int in_use;
} student;

void eatstdin();
int menu();
char compute_grade(float marks);
void Add_student(student **PPstudents,size_t *Psize);
void Find_student(student **PPstudents,size_t *Psize);
void Remove_student(student **PPstudents, size_t *Psize);
void display_all(student **PPstudents, size_t *Psize);
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
    student *Pstudents = (student*)malloc(size*sizeof(student));
    for(int i =0;i<size;i++){
        Pstudents[i].in_use = 0;
        strcpy(Pstudents[i].name,"\0");
        Pstudents[i].roll_no = 0;
        strcpy(Pstudents[i].course,"\0");
        Pstudents[i].marks = 0;
        Pstudents[i].grade = ' ';
    }
    while(1){
        int c = menu();
        if(c == 1) Add_student(&Pstudents,&size);
        else if(c == 2) Find_student(&Pstudents,&size);
        else if(c == 3) Remove_student(&Pstudents,&size);
        else if(c == 4) display_all(&Pstudents,&size);
        else if(c == 5) break;
    }
    free(Pstudents);
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
char compute_grade(float marks){
    if(marks>=90) return 'A';
    else if(marks>=75) return 'B';
    else if(marks>=60) return 'C';
    else if(marks>=40) return 'D';
    else return 'F';
}
int menu(){
    int c;
    while(1){
        printf("\033c");
        printf("Student Record System\n");
        printf("1. Add Student\n");
        printf("2. Find Student\n");
        printf("3. Remove Student\n");
        printf("4. Display All\n");
        printf("5. Exit\n");
        printf("Choice: ");
        if(intinput("Enter Choice(1,2,3,4): ",&c)) continue;
        return c;
    }
}
void Add_student(student **PPstudents,size_t *Psize){
    char name[31];
    int roll_no;
    char course[21];
    float marks;
    printf("\033c");
    if(strinput("Enter Name of student: ",name,31)){
        printf("Error");
        sleep(1);
        return;
    }
    if(intinput("Enter Roll Number: ",&roll_no)){
        printf("Error");
        sleep(1);
        return;
    }
    if(strinput("Enter Course: ",course,21)){
        printf("Error");
        sleep(1);
        return;
    }
    if(floatinput("Enter Marks: ",&marks)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPstudents)[i].in_use == 1 &&
            (*PPstudents)[i].roll_no==roll_no){  
                char c =' ';
                while(chinput("Student with this Roll No. already exists. Overwrite?(y/n)",&c,"yn")!=0);
                if(c=='y'){
                    strcpy((*PPstudents)[i].name,name);
                    strcpy((*PPstudents)[i].course,course);
                    (*PPstudents)[i].marks=marks;
                    (*PPstudents)[i].grade=compute_grade(marks);
                } return;
        }   
    }
    for(int i = 0; i < *Psize; i++){
        if(!(*PPstudents)[i].in_use){
            strcpy((*PPstudents)[i].name,name);
            (*PPstudents)[i].roll_no=roll_no;
            strcpy((*PPstudents)[i].course,course);
            (*PPstudents)[i].marks=marks;
            (*PPstudents)[i].grade=compute_grade(marks);
            (*PPstudents)[i].in_use = 1;
            break;
        }
    }
    printf("Done.");
    sleep(1);
}
void Find_student(student **PPstudents,size_t *Psize){
    int roll_no;
    printf("\033c");
    if(intinput("Enter Roll Number to search: ",&roll_no)){
        printf("Error");
        sleep(1);
        return;
    }
    for(int i = 0;i<*Psize;i++){
        if((*PPstudents)[i].in_use == 1 &&
            (*PPstudents)[i].roll_no==roll_no){  
                printf("Name: %s\nCourse: %s\nMarks: %.2f\nGrade: %c\nPress [Enter] to return to the menu...",
                    (*PPstudents)[i].name,(*PPstudents)[i].course,(*PPstudents)[i].marks,(*PPstudents)[i].grade);
                getchar();
                return;
        }   
    }
    printf("Failed.");
    sleep(1);
}
void Remove_student(student **PPstudents, size_t *Psize){
    int roll_no;
    printf("\033c"); // Clear screen
    if (intinput("Enter Roll Number of student to remove: ", &roll_no)){
        printf("Error\n");
        sleep(1);
        return;
    }
    
    for (size_t i = 0; i < *Psize; i++){
        if ((*PPstudents)[i].in_use == 1 &&
            (*PPstudents)[i].roll_no == roll_no){  
                
                char c = ' ';
                printf("\nStudent Found: %s | Roll No: %d | Course: %s | Marks: %.2f\n", 
                       (*PPstudents)[i].name, (*PPstudents)[i].roll_no, 
                       (*PPstudents)[i].course, (*PPstudents)[i].marks);
                
                while (chinput("Are you sure you want to remove this student? (y/n): ", &c, "yn") != 0);
                if (c == 'y'){
                    (*PPstudents)[i].in_use = 0;
                    (*PPstudents)[i].roll_no = 0;
                    (*PPstudents)[i].marks = 0.0;
                    (*PPstudents)[i].grade = ' ';
                    strcpy((*PPstudents)[i].name, "");
                    strcpy((*PPstudents)[i].course, "");
                    
                    printf("Student successfully removed.\n");
                } else{
                    printf("Removal canceled.\n");
                }
                sleep(1);
                return;
        }   
    }
    
    printf("Student not found.\n");
    sleep(1);
}
void display_all(student **PPstudents, size_t *Psize){
    printf("\033c");
    printf("====================CURRENT_STUDENT_RECORDS====================\n");
    printf("%-4s | %-20s | %-8s | %-15s | %6s | %5s\n", "No.", "Name", "Roll No", "Course", "Marks", "Grade");
    printf("-----------------------------------------------------------------\n");
    
    int count = 0;
    for (size_t i = 0; i < *Psize; i++) {
        if ((*PPstudents)[i].in_use == 1) {
            count++;
            printf("%-4d | %-20s | %-8d | %-15s | %6.2f | %5c\n", 
                   count,
                   (*PPstudents)[i].name, 
                   (*PPstudents)[i].roll_no, 
                   (*PPstudents)[i].course, 
                   (*PPstudents)[i].marks,
                   (*PPstudents)[i].grade);
        }
    }
    if (count == 0) {
        printf("               [ No student records found ]            \n");
    }
    printf("=================================================================\n");
    printf("\nPress [Enter] to return to the menu...");
    getchar(); 
}