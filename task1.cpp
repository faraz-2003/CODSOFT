#include<iostream>
#include<cstdlib>

int main()
{   
    printf("Welcome to the Number Guess!!!!!!\t(The Range is 0 to 99)\n");
    srand((unsigned) time(NULL));
    int target=rand()%100;
    bool flag=true;
    int count = 0;
    while(flag){
        int guess=0;
        printf("Enter your guess : ");
        scanf("%d",&guess);
        count=count+1;
        if(guess>target){
            printf("Too high\n");
        }
        else if(guess<target){
            printf("Too low\n");
        }
        else{
            printf("\nYes you are Correct\t You took %d guesses \nCongragulations!!!!!!!\n\nThank You",count);
            flag=false;
        }
    }
    return 0;
}