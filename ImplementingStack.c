#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10

int top, s[10], element;

// check if stack is full
int isFull() {
    if(top == STACK_SIZE - 1)
        return 1;
    else
        return 0;
}

// check if empty
int isEmpty() {
    if(top == -1)
        return 1;
    else 
        return 0;
}

// peek function (first element of stack)
void peek() {
    if(isEmpty()) {
        printf("Stack underflow\n");
        return;
    }
    else
        printf("Element on the top is: %d\n", s[top]);
        printf("\n");
}

// enter a value into the stack
void push() {
    if(isFull()) {
        printf("Stack Overflow!!!\n");
        return;
    }
    else {
        top++;
        s[top] = element;
        printf("The value %d has been pushed into the stack.\n", element);
        printf("\n");
    }
}

// To delete elements from the stack
void pop() {
    if(isEmpty()) {
        printf("Stack underflow\n");
        return;
    }
    else {
        printf("Item deleted is %d\n", s[top]);
        top--;
        printf("\n");
    }
}

// displaying everything on the stack
void display() {
    int i;
    if(isEmpty()) {
        printf("Stack underflow!!!\n No elements to display here.\n");
        return;
    }
    else {
        printf("The contents of the stack are:\n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", s[i]);
        }
    }
}

// main func
int main() {
    int choice;
    top = -1;
    for(;;) {   // for(;;) for infinite looping similar to while(1)
        printf("Welcome to Stack Operations\n");
        printf("1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.Exit\n");
        printf("Enter your Preference: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to be inserted: \n");
                scanf("%d", &element);
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;  // Added break to exit the switch statement
            case 5:
                printf("Exiting your life just like her....");
                exit(0);  // Added exit(0) to terminate the program
            default:
                printf("Select something from your league bro :[\n");
                printf("\n");
        }
    }
    return 0;
}
