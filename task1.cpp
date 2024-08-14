#include <stdio.h>

int main()
{
    int target=0;
    bool flag=true;
    printf("Enter the number to be guessed : ");
    scanf("%d",&target);
    while(flag){
        int guess=0;
        printf("Enter your guess : ");
        scanf("%d",&guess);
        if(guess>target){
            printf("Too high\n");
        }
        else if(guess<target){
            printf("Too low\n");
        }
        else{
            printf("Correct\n");
            flag=false;
        }
    }
    }