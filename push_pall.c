#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being processed
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int is_integer(const char *str)
{
    if (!str || *str == '\0')
        return (0);

    while (*str)
    {
        if (!isdigit(*str) && *str != '-' && *str != '+')
            return (0);
        str++;
    }

    return` (1);
}
