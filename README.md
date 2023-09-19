# project : Stacks, Queues - LIFO, FIFO

## Resources

- [How do I use extern to share variables between source files in C?](https://intranet.alxswe.com/rltoken/0KVWTdE8xXy__jUfBfakCw "How do I use extern to share variables between source files in C?")
- [Stacks and Queues in C](https://intranet.alxswe.com/rltoken/udmomL4F4mF630D2Z-ltqg "Stacks and Queues in C")
- [Stack operations](https://intranet.alxswe.com/rltoken/fj_-SJXW-pWxgAnstsARoQ "Stack operations")
- [Queue operations](https://intranet.alxswe.com/rltoken/6Y_GVoIH_rV45xd7w0a9FA "Queue operations")

## General

- What do LIFO and FIFO mean?
- What is a stack, and when to use it?
- What is a queue, and when to use it?
- What are the common implementations of stacks and queues?
- What are the most common use cases of stacks and queues ?
- What is the proper way to use global variables ?

## more info

1. Please use the following data structures for this project. Don’t forget to include them in your header file.

```c
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
```

```c
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
```

## Compilation & Output

`gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

### task mandatory

The monty program

Usage: `monty file`
where file is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
