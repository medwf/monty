#ifndef MONTY_H
#define MONTY_H

/* Header file  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global struct */
/**
 * struct structure_global - data for stack
 * @int_to_push: an integer for push
 * @file: a pointer to file.
 * @head: a pointer to linked list.
 * @array: a doule pointer (command process).
 */
typedef struct structure_global
{
	FILE *file;
	int int_to_push;
	stack_t *head;
	char **array;
} global_struct;
extern global_struct gs;

/* prototype */
/* in --- fun_helper0 you will found ---*/
char **divide_arg(char *line);
void dte_space(char *str);
void is_open(char *file_name);
int check_number(char *number);
void process(char **array, unsigned int line_number);

/* in --- fun_allocate you will found ---*/
void free_array(char **array);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_stack(stack_t *h);

/* in --- stack_opcode you will found --- */
void handle_push(stack_t **stack, unsigned int line_number);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);

/* in --- more_stack_opcode you will found --- */
void handle_add(stack_t **stack, unsigned int line_number);
void handle_sub(stack_t **stack, unsigned int line_number);
void handle_div(stack_t **stack, unsigned int line_number);
void handle_mul(stack_t **stack, unsigned int line_number);
void handle_mod(stack_t **stack, unsigned int line_number);

/* in --- more_1_stack_opcode you will found --- */
void handle_pchar(stack_t **stack, unsigned int line_number);
void handle_pstr(stack_t **stack, unsigned int line_number);
void handle_rotl(stack_t **stack, unsigned int line_number);
void handle_rotr(stack_t **stack, unsigned int line_number);
#endif
