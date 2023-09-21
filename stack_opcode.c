#include "monty.h"
/**
 * handle_push - a function that pushes an element to the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *last_node = NULL;
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

	if (gs._switch == 0)
	{
		if (*stack)
		{
			new->next = *stack;
			(*stack)->prev = new;
		}
		*stack = new;
	}
	if (gs._switch == 1)
	{
		last_node = *stack;
		if (last_node)
		{
			while (last_node->next)
				last_node = last_node->next;
			new->prev = last_node, last_node->next = new;
		}
		else
			*stack = new;
	}
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
 * handle_pint - a function that print last element.
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
/**
 * handle_pop - a function that pop an element in the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(gs.head), free_array(gs.array);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
/**
 * handle_swap - a function that swap two elements in the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{
	int swap = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(gs.head), free_array(gs.array);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}
