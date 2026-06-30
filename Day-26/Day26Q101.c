//Write a program to Create number guessing game.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
unsigned long int seed = 1796;
long int random(){
    int mul =54649;
    int bias = 336665;
    seed = (unsigned long int)seed*mul+bias;
    return seed;
}
int randint(int start,int end){
    return random()%((unsigned long int)((end-start+1)))+start;
}
void game1(){
    restart:
    system("cls");
    printf("_____Number Guessing Game_____\nGuess the number between 1 to 100\nenter -1 to quit\n");
    seed = (unsigned long int)time(NULL);
    int num = randint(1,100);
    int choice ;
    printf("Enter first guess to start the game: ");
    while(scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a number: ");
        char c;
        while ((c = getchar()) != '\n' && c != EOF); 
    }
    
     
    if(choice==-1) return;
    int diff = (num-choice);
    if(diff == 0){
        printf("You guessed it in first try!\n");
        printf("Would you like to restart?(y/n) : ");
        while(1){
            scanf(" %c",&choice);
            if(choice == 'y'){
                goto restart;
            }
            else if(choice == 'n'){
                goto quit;
            }
            else{
                printf("Try again :");
            }
        }
        
    }
    diff = (diff<0)?-diff:diff;
    int prev = diff;
    int tries = 2;
    while(1){
        printf("Make a guess : ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            char c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue; 
        }
        if(choice==-1) goto quit;
        diff = (num-choice);
        diff = (diff<0)?-diff:diff;
        if(diff == 0){
            printf("You guessed it in %d tries!\n",tries);
            printf("Would you like to restart?(y/n) : ");
            while(1){
                scanf(" %c",&choice);
                if(choice == 'y'){
                    goto restart;
                }
                else if(choice == 'n'){
                    goto quit;
                }
                else{
                    printf("Try again :");
                }
            }
            
        }

        if(diff>prev){
            if(diff>30) printf("Very Cold\n");
            else printf("Colder\n");
        }
        else{
            if(diff<3) printf("Very Hot\n");
            else printf("Hotter\n");
        }
        prev = diff;
        tries++;
    }
    quit:
}
int main(){
    game1();
    return 0;
}