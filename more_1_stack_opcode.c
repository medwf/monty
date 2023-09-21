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
	(void)line_number;

	while (prnt)
	{
		if (!prnt->n || prnt->n < 0 || prnt->n > 127)
			break;
		fprintf(stdout, "%c", prnt->n);
		prnt = prnt->next;
	}
	fprintf(stdout, "\n");
}

/**
 * handle_rotl - a function that :top element of the stack becomes the last one
 *   and the second top element of the stack becomes the first one
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;
	int rot_left = 0;
	(void)line_number;

	if (!nav || !nav->next)
		return;

	rot_left = nav->n;
	while (nav->next)
	{
		nav->n = nav->next->n;
		nav = nav->next;
	}
	nav->n = rot_left;
}

/**
 * handle_rotr - a function that : The last element of the stack
 *                          becomes the top element of the stack
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *nav = *stack;
	int rot_right = 0;
	(void)line_number;

	if (!nav || !nav->next)
		return;

	while (nav->next)
		nav = nav->next;
	rot_right = nav->n;

	while (nav->prev)
	{
		nav->n = nav->prev->n;
		nav = nav->prev;
	}
	nav->n = rot_right;
}

/**
 * handle_switch - a function that switch between stack and queue.
 * @stack: a double pointer to linked list
 * @line_number: an integer represent line number
 */
void handle_switch(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (strcmp(gs.array[0], "stack") == 0)
		gs._switch = 0;
	if (strcmp(gs.array[0], "queue") == 0)
		gs._switch = 1;
}
