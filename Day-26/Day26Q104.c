//104 Write a program to Create quiz application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct quizapplicants{
    char name[21];
    int rollno;
    int score;
    int active;
} acc;
acc acclist[30];
int create(int rollno,char name[]){
    for(int id = 0; id<30;id++){
        if(acclist[id].active==0){
            acclist[id].rollno=rollno;
            strcpy(acclist[id].name,name);
            acclist[id].score = 0;
            acclist[id].active = 1;
            return id;
        }
    }
    return -1;
}
int find_rollno(int rollno){
    for(int id = 0; id<30;id++){
        if(rollno==acclist[id].rollno&&acclist[id].active){
            return id;
        }
    }
    return -1;
}
int menu(){
    int choice;
    while(1){
        system("cls");
        printf("_________________Menu____________________\n");
        printf("Enter Command no. to run :\n1. Start quiz\n2. Quit\n");
        printf("Command : ");
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        return choice;
    }
}
int quiz(){
    int q = 1;
    int score = 0;
    int choice;
    while(1){
        system("cls");
        printf("____________Space quiz_____________________\nDo not close the window\n");
        
        if(q==1){
            printf("Q%d. What is the hottest planet in our solar system, with surface temperatures reaching over 450°C due to a thick greenhouse effect?\nA) Mercury\nB) Mars\nC) Venus\nD) Jupiter\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 3){ // Venus is C
                score++;
            } 
            q++;
        }
        else if(q==2){
            printf("Q%d. What is the invisible force that keeps planets in orbit around the Sun and holds galaxies together?\nA) Magnetism\nB) Friction\nC) Gravity\nD) Inertia\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 3){ // Gravity is C
                score++;
            } 
            q++;
        }
        else if(q==3){
            printf("Q%d. What is the name of the boundary around a black hole from which nothing, not even light, can escape?\nA) The Event Horizon\nB) The Singularity\nC) The Core\nD) The Wormhole\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 1){ // Event Horizon is A
                score++;
            } 
            q++;
        }
        else if(q==4){
            printf("Q%d. Which type of space object is essentially a giant ball of ice, dust, and rock that develops a visible tail when passing close to the Sun?\nA) Asteroid\nB) Comet\nC) Meteor\nD) Nebula\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 2){ // Comet is B
                score++;
            } 
            q++;
        }
        else if(q==5){
            printf("Q%d. Roughly how long does it take for light traveling from the Sun to reach the Earth?\nA) 8 seconds\nB) 8 minutes\nC) 8 hours\nD) 8 days\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            } 
            if(choice<1 || choice>4){
                continue;
            } 
            if(choice == 2){ // 8 minutes is B
                score++;
            } 
            q++;
        }
        else if(q==6){
            printf("Q%d. What is the name of our home galaxy, which is shaped like a large spiral?\nA) Andromeda\nB) Milky Way\nC) Sombrero\nD) Orion\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 2){ // Milky Way is B
                score++;
            } 
            q++;
        }
        else if(q==7){
            printf("Q%d. What is the name of the largest planet in our solar system, famous for its Great Red Spot storm?\nA) Saturn\nB) Neptune\nC) Jupiter\nD) Uranus\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 3){ // Jupiter is C
                score++;
            } 
            q++;
        }
        else if(q==8){
            printf("Q%d. Which moon in our solar system is the only one known to have a dense atmosphere and liquid lakes of methane on its surface?\nA) Europa\nB) Titan\nC) Ganymede\nD) Enceladus\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 2){ // Titan is B
                score++;
            } 
            q++;
        }
        else if(q==9){
            printf("Q%d. What process powers a star like our Sun, where hydrogen atoms merge together to form helium and release massive amounts of energy?\nA) Nuclear fission\nB) Nuclear fusion\nC) Chemical combustion\nD) Radioactive decay\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            } 
            if(choice<1 || choice>4){
                continue;
            } 
            if(choice == 2){ // Nuclear fusion is B
                score++;
            } 
            q++;
        }
        else if(q==10){
            printf("Q%d. What instrument did astronomers use to capture the deep field images showing thousands of galaxies in a tiny patch of sky?\nA) James Webb Space Telescope\nB) Arecibo Observatory\nC) Voyager 1\nD) International Space Station\nYour Answer (1-4): ",q);
            if (scanf("%d", &choice) != 1) {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                continue;
            }  
            if(choice<1 || choice>4){
                continue;
            }
            if(choice == 1){ // James Webb Space Telescope is A
                score++;
            } 
            q++;
        }
        else if(q > 10){
            return score;
        }
    }
}

void quizmenu(){
    char choice;
    int rollno=-1;
    char name[21];name[0]='\0';
    int id=-1;
    while(1){
        system("cls");
        printf("_________________quizmenu__________________\nenter /quit or -1 to exit\n");
        if(rollno<0){
            printf("Enter rollno: ");
            scanf(" %d",&rollno);
            if(rollno<0) break;
            continue;
        }
        if(name[0]!='\0' && rollno>=0 && id!=-1){
            printf("Time : indefinite\nAttempt : 1\nTo start enter y\nEnter any other key to exit\n");
            scanf(" %c",&choice);
            if(choice=='y'){
                system("cls");
                printf("Loading...");
                sleep(3);
                int score = quiz();
                system("cls");
                printf("You scored %d/10",score);
                sleep(5);
                break;
            }
            else{
                acclist[id].active = 0;
                break;
            }
        }
        if(name[0]!='\0')printf("Name: %s\n",name);
        printf("Rollno: %d\n",rollno);
        id = find_rollno(rollno);
        sleep(1);
        if((id!=-1)){
            printf("You cannot enter quiz again.");
            rollno = -1;
            sleep(2);
            continue;;
        }
        if(name[0]=='\0'){
            printf("Enter name: ");
            scanf(" %s",name);
            if(strcmp(name,"/quit")==0) break;
            if(strlen(name)<2){
                printf("Try Again");
                name[0]='\0';
                sleep(2);
            }
            continue;;
        }
        if((id=create(rollno,name))==-1){
            printf("Site is closed\nPlease contact the admin.");
            sleep(2);
            break;
        }
    }
}

int main() {
    for(int i = 0;i<30;i++){
        acclist[i].active=0;
    }
    while(1){
        int choice= menu();
        if(choice == 1) quizmenu();
        else if(choice == 2) break;
    }
    return 0;
}