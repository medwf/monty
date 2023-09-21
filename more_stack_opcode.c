#include "monty.h"
/**
 * handle_add - a function that add two last elements in the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_add(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        free_stack(gs.head), free_array(gs.array);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    *stack = (*stack)->next;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * handle_sub - a function that sub two last elements in the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_sub(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_stack(gs.head), free_array(gs.array);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    *stack = (*stack)->next;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * handle_div - a function that div two last elements in the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_div(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        free_stack(gs.head), free_array(gs.array);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    *stack = (*stack)->next;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}