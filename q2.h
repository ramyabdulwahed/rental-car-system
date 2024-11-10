/*
name: Ramy Abdulwahed
student id: 1299971
date: 24/10/2024
Assignment name: A2
*/

#ifndef Q1_H
#define Q1_H
#include <ctype.h>

/*
We will be creating a stack to solve our problem
This stack will follow a linked list based approach
*/
typedef struct operand {
  double value;
  struct operand *next;
} Operand;



/* Function defintions for our stack */

void push(Operand ** stack ,double value);
double pop(Operand ** stack);
void print(Operand * stack);

#endif
