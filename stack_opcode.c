#include "monty.h"
/**
 * handle_push - a function that pushes an element to the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	if (!stack)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = gs.int_to_push;
	new->next = NULL;
	new->prev = NULL;

	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * handle_pall - a function that print all element.
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *prnt = NULL;
	(void)line_number;

	prnt = *stack;

	while (prnt)
	{
		fprintf(stdout, "%d\n", prnt->n);
		prnt = prnt->next;
	}
}
/**
 * handle_pint - a function that print all element.
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(gs.head), free_array(gs.array);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
