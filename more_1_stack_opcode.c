#include "monty.h"

/**
 * handle_pchar - a function that print char of last element.
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(gs.head), free_array(gs.array);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(gs.head), free_array(gs.array);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * handle_pstr - a function that print string start
 *                from last last element to stop value 0.
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *prnt = *stack;
	(void) line_number;

	while (prnt)
	{
		if (!prnt->n || prnt->n < 0 || prnt->n > 127)
			break;
		fprintf(stdout, "%c", prnt->n);
		prnt = prnt->next;
	}
	fprintf(stdout, "\n");
}
