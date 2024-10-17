#include<stdio.h>
#include<stdlib.h>

#define MAX 10  // Define maximum size of the stack

int stack_arr[MAX];  // Array to store stack elements
int top = -1;  // Initialize top to -1 (indicating stack is empty)

// Function prototypes
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main()
{
    int choice, item;
    while(1)
    {
        // Display menu options
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display the top element\n");
        printf("4. Display all stack elements\n");
        printf("5. Quit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);  // Get user choice

        switch(choice)
        {
            case 1:  // Push operation
                printf("\nEnter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:  // Pop operation
                item = pop();
                printf("\nPopped item is: %d\n", item);
                break;

            case 3:  // Display the top element
                printf("\nItem at the top is: %d\n", peek());
                break;

            case 4:  // Display all stack elements
                display();
                break;

            case 5:  // Exit program
                exit(1);

            default:  // Invalid choice
                printf("\nWrong choice\n");
        }
    }
    return 0;
}

// Function to push an element onto the stack
void push(int item)
{
    if(isFull())  // Check if stack is full
    {
        printf("\nStack is Full [OVERFLOW!]\n");
        return;
    }
    top = top + 1;  // Increment top
    stack_arr[top] = item;  // Add item to the stack
}

// Function to pop an element from the stack
int pop()
{
    int item;
    if(isEmpty())  // Check if stack is empty
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    item = stack_arr[top];  // Get the top item
    top = top - 1;  // Decrease top
    return item;  // Return popped item
}

// Function to display the top element of the stack
int peek()
{
    if(isEmpty())  // Check if stack is empty
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    return stack_arr[top];  // Return top item
}

// Function to check if stack is empty
int isEmpty()
{
    if(top == -1)
        return 1;  // Stack is empty
    else
        return 0;  // Stack is not empty
}

// Function to check if stack is full
int isFull()
{
    if(top == MAX - 1)
        return 1;  // Stack is full
    else
        return 0;  // Stack is not full
}

// Function to display all elements in the stack
void display()
{
    int i;
    if(isEmpty())  // Check if stack is empty
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack elements:\n");
    for(i = top; i >= 0; i--)  // Print elements from top to bottom
        printf("%d\n", stack_arr[i]);
}
