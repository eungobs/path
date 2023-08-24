#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

typedef struct 
{
    Node *top;
} Stack;

void initStack(Stack *stack) 
{
    stack->top = NULL;
}

int isEmpty(Stack *stack) {
    return (stack->top == NULL);
}

void push(Stack *stack, int value) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) 
{
    if (!isEmpty(stack)) 
    {
        Node *temp = stack->top;
        int value = temp->data;
        stack->top = temp->next;
        free(temp);
        return (value);
    } 
    else 
    {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
}

void swap(Stack *stack) 
{
    if (stack->top != NULL && stack->top->next != NULL) 
    {
        int value1 = pop(stack);
        int value2 = pop(stack);
        push(stack, value1);
        push(stack, value2);
    } 
    else 
    {
        printf("Error: can't swap, stack too short\n");
        exit(EXIT_FAILURE);
    }
}

int main() 
{
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    swap(&stack);

    while (!isEmpty(&stack)) 
    {
        printf("%d\n", pop(&stack));
    }

    swap(&stack);

    return (0);
}
