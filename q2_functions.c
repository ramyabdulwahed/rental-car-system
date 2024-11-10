/*
Name:Ramy Abdulwahed
Student ID: 1299981
Assignment 2, Question 2
*/

#include "q2.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * Pushes a new value onto the stack.
 *
 * @param stack Pointer to the pointer of the stack's head.
 * @param value The value to be added to the stack.
 */
void push(Operand **stack, double value){

    Operand * temp;
    temp = malloc(sizeof(Operand)); //allocate memory for the new node
    temp->value = value;
    temp->next = *stack; //update the node
    *stack = temp; //head will point to last element in
}


/**
 * Pops the top value from the stack and returns it.
 *
 * @param stack Pointer to the pointer of the stack's head.
 * @return The value that was at the top of the stack.
 */
double pop(Operand **stack){

    double value_popped = 0.0;
    Operand * temp;
    temp =  *stack;
    if (temp == NULL){
      printf ("Stack is empty.\n");
      return 0;
    }
    value_popped = temp->value;
    *stack = (*stack)->next; //point to the second element so we can remove the first
    free(temp); //free old node
    return value_popped;


}

/**
 * Prints all values in the stack.
 * 
 * @param stack Pointer to the stack's head.
 */
void print(Operand *stack){

    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while (stack != NULL){
         printf ("Value = %lf", stack->value);
         stack = stack->next;
    }
    
}




