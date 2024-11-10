/*
name: Ramy Abdulwahed
student id: 1299971
date: 24/10/2024
Assignment name: A2
*/

#include "q2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

  //Pointer to the stack
  double first_popped_value, second_popped_value, answer;
  double final_answer = 0.0;
  Operand * stack = NULL;
  double number;
  char op;

    if (argc < 2) {
        printf("Incorrect input \n");
        return 0;
    }

  for (int i = 0; i < strlen(argv[1]); i++){
     //parse integer
      if (isdigit((argv[1])[i])){
         number = (argv[1])[i] - '0'; //convert char to a digit usign the ascii char value
        push(&stack, number); // as long as it it is a number push double to stack
      }
      else if ((argv[1])[i] == '+' || (argv[1])[i] == '-' || (argv[1])[i] == '*' || (argv[1])[i] == '/'){ //check what type of operand
         op = (argv[1])[i]; //assign operator to op
         if (stack != NULL){
            first_popped_value = pop(&stack); //pop 2nd digit
         }
         else{
            printf ("Error: Stack is Empty.\n");
            return 0;
         }
         if (stack != NULL){
           second_popped_value = pop (&stack); //pop first digit
         }
         else{
            printf ("Error: Stack is Empty.\n");
            return 0;
         }

         // if we popped both we perform the calculation
         switch (op) {
            case '+':
                answer = second_popped_value + first_popped_value;
                break;
            case '-':
                answer = second_popped_value - first_popped_value;
                break;
            case '*':
                answer = second_popped_value * first_popped_value;
                break;
            case '/':
                if (first_popped_value != 0) {
                answer = second_popped_value / first_popped_value;
                } else {
                    printf("Error: Division by zero.\n");
                    return 0;
                }
                break;
            default:
                printf("Unknown operator: %c\n", op);
                break;
       }//switch bracket

       push (&stack, answer);


      } //else if bracket
      else {
        printf("Error: Unknown operator: %c\n", (argv[1])[i]);
        return 0;
        }
  }//for loop
  
    final_answer = pop(&stack);
    printf("Final Answer = %.2lf\n", final_answer);

  return 0;
}
