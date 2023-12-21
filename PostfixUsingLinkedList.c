#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <ctype.h> 
struct Node { 
 int data; 
 struct Node* next; 
}; 
typedef struct Node Node; 
struct Stack { 
 Node* header; 
}; 
typedef struct Stack Stack; 
// Function to initialize the stack 
void initializeStack(Stack* stack) { 
 stack->header = NULL; 
} 
// Function to push a value onto the stack 
void push(Stack* stack, int value) { 
 Node* newNode = (Node*)malloc(sizeof(Node)); 
 if (newNode == NULL) { 
 printf("Memory allocation failed\n"); 
 exit(EXIT_FAILURE); 
 } 
 newNode->data = value; 
 newNode->next = stack->header; 
 stack->header = newNode; 
} 
// Function to pop a value from the stack 
int pop(Stack* stack) { 
 if (stack->header == NULL) { 
 printf("Stack underflow\n"); 
 exit(EXIT_FAILURE); 
 } 
 Node* temp = stack->header; 
 int value = temp->data; 
 stack->header = temp->next; 
 free(temp); 
 return value; 
} 
// Function to check if the stack is empty 
int isEmpty(Stack* stack) { 
 return stack->header == NULL; 
} 
// Function to evaluate a postfix expression 
int evaluatePostfix(char* expression) { 
 Stack stack; 
 initializeStack(&stack); 
 for (int i = 0; expression[i] != '\0'; i++) { 
 if (isdigit(expression[i])) { 
 int num = 0; 
 while (isdigit(expression[i])) { 
 num = num * 10 + (expression[i] - '0'); 
 i++; 
} 
 i--; // Adjust for the extra increment in the loop 
 push(&stack, num); 
 } else if (expression[i] == ' ' || expression[i] == '\n') { 
 continue; 
 } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || 
 expression[i] == '/' || expression[i] == '%') { 
 if (isEmpty(&stack)) { 
 printf("Invalid expression\n"); 
 exit(EXIT_FAILURE); 
 } 
 int operand2 = pop(&stack); 
 if (isEmpty(&stack)) { 
 printf("Invalid expression\n"); 
 exit(EXIT_FAILURE); 
 } 
 int operand1 = pop(&stack); 
 int result; 
 switch (expression[i]) { 
 case '+': 
 result = operand1 + operand2; 
 break; 
 case '-': 
 result = operand1 - operand2; 
 break; 
 case '*': 
 result = operand1 * operand2; 
 break; 
 case '/': 
 if (operand2 == 0) { 
 printf("Division by zero\n"); 
 exit(EXIT_FAILURE); 
 } 
 result = operand1 / operand2; 
 break; 
 case '%': 
 if (operand2 == 0) { 
 printf("Modulo by zero\n"); 
 exit(EXIT_FAILURE); 
 } 
 result = operand1 % operand2; 
 break; 
 } 
 push(&stack, result); 
 } else { 
 printf("Invalid character in expression\n"); 
 exit(EXIT_FAILURE); 
 } 
 } 
 if (isEmpty(&stack)) { 
 printf("Invalid expression\n"); 
 exit(EXIT_FAILURE); 
 } 
 int finalResult = pop(&stack); 
 if (!isEmpty(&stack)) { 
 printf("Invalid expression\n"); 
 exit(EXIT_FAILURE); 
 } 
 return finalResult; 
} 
int main() { 
 char expression[100]; 
 printf("Enter a postfix expression: "); 
 fgets(expression, sizeof(expression), stdin); 
 // Evaluate the expression 
 int result = evaluatePostfix(expression); 
 printf("Result: %d\n", result); 
 return 0; 
} 