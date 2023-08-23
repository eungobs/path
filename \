#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <monty.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

stack_t *stack = NULL;

void push(stack_t **stack, int value, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
  stack_t *current = *stack;
    while (current)
    {
        fprintf("%d\n", current->n);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 1;
    ssize_t nread;

    while ((nread = getline(&line, &len, file)) != -1)
    {
        char opcode[10];
        int value;

       if (sscanf(line, "%9s %d", opcode, &value) == 2)
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, value, line_number);
            
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
        else if (sscanf(line, "%9s", opcode) == 1)
        {
            if (strcmp(opcode, "pall") == 0)
                pall(&stack, line_number);
            
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }

        line_number++;
    }

    free(line);
    fclose(file);
    return (0);
}
