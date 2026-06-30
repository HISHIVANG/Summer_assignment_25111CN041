//Write a program to Create menu-driven calculator
#include <stdio.h>
#include <math.h>
void calculator();
int main(){

    calculator();
    return 0;
}
void calculator(){
    float x,y,z;
    char o;
    int xa=0,ya=0,za=0,oa=0;
    char garbage;
    while(1){
        printf("\033c");
        printf("====CALCULATOR====\n");
        if(xa){printf("%.2f ",x);}
        else{printf("X ");}

        if(oa){printf("%c ",o);}
        else{printf("<> ");}

        if(ya){printf("%.2f ",y);}
        else{printf("Y ");}

        if(za){
            printf("= %.2f \nEnter any key to continue.",z);
            scanf(" %c",&garbage);
            xa=ya=za=oa=0;
            continue;
        }
        else{printf("= Result \n");}

        printf(">> ");
        if(!xa){
            scanf(" %f",&x);
            xa=1;
        }
        else if(!oa){
            scanf(" %c",&o);
            if(o=='q'){break;}
            oa=1;
        }
        else if(!ya){
            scanf(" %f",&y);
            ya=1;
        }
        else{
            za = 1;
            if(o == '+'){
                z = x+y;
            }
            else if(o == '-'){
                z = x-y;
            }
            else if(o == '*'){
                z = x*y;
            }
            else if(o == '/'){
                z = x/y;
            }
            else if(o == '^'){
                z = pow(x,y);
            }
            else{
                printf("Invalid. Enter any key to continue.");
                scanf(" %c",&garbage);
                xa=0,ya=0,za=0,oa=0;
                continue;
            }
        }
    }
    
}