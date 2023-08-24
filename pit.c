#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *stack) 
{
    stack->top = NULL;
}

int isEmpty(Stack *stack) 
{
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

void pint(Stack *stack) 
{
    if (!isEmpty(stack)) 
    {
        int value = stack->top->data;
        printf("%d\n", value);
    } 
    else 
    {
        printf("Error: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
}

int main() 
{
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack,3);
    pint(&stack);

    while (!isEmpty(&stack))
        pint(&stack);
    }

    pint(&stack);

    return (0);
}
