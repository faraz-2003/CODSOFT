#include <stdio.h>

int main() {
    bool flag = true;
    printf("!!________CALCULATOR________!!\n\n");
    while(flag){
      int num1,num2;
      char opr;
      printf("\nEnter the first number : ");
      scanf("%d", &num1);
      printf("Enter the second number : ");
      scanf("%d", &num2);
      printf("Enter the operation to perform ( +, -, *, / ): ");
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
          printf("\nThank you!!!\n");
          }
    }
    return 0;
}