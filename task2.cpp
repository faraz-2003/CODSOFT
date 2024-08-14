#include <stdio.h>

int main() {
    bool flag = true;
    while(flag){
      int num1,num2;
      char opr;
      printf("Enter the first number : ");
      scanf("%d", &num1);
      printf("Enter the second number : ");
      scanf("%d", &num2);
      printf("Enter the operator : ");
      scanf(" %c", &opr);
      switch(opr){
        case '+':
          printf("The result is : %d", num1+num2);
          break;
        case '-':
          printf("The result is : %d", num1-num2);
          break;
        case '*':
          printf("The result is : %d", num1*num2);
          break;
        case '/':
          if(num2!=0)
          printf("The result is : %d", num1/num2);
          else
          printf("Cannot divide by zero");
          break;
        default:
          printf("Invalid operator");
        }
        printf("\nDo you want to continue? (y/n) ");
        char ch;
        scanf(" %c", &ch);
        if(ch=='n'){
          flag = false;
          printf("Thank you!");
          }
    }
    return 0;
}