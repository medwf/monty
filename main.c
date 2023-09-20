#include "monty.h"
global_struct gs;
/**
 * print_error - a finction that print error
 * @err: a pointer to string.
 */
void print_error(char *err)
{
	fprintf(stderr, "%s\n", err);
	exit(EXIT_FAILURE);
}
/**
 * main - Entry points
 * Description: create an interpreter for Monty ByteCodes files.
 * @argc: the number of argument
 * @argv: an arrays of argument
 * Return: 0 on Suceess, 1 if failed.
 */
int main(int argc, char **argv)
{
	char line[100], **array = NULL;
	unsigned int i, count_line = 1;
	instruction_t in[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{NULL, NULL},
	};

	if (argc == 2)
		is_open(argv[1]);
	else
		print_error("USAGE: monty file");

	gs.head = NULL;
	while (fgets(line, sizeof(line), gs.file) != NULL)
	{
		line[strlen(line) - 1] = '\0', array = divide_arg(line);
		if (array)
		{
			if (strcmp(array[0], "push") == 0)
			{
				if (!(array[1] && check_number(array[1])))
				{
					fprintf(stderr, "L%d: usage: push integer\n", count_line);
					free_stack(gs.head), free_array(array);
					exit(EXIT_FAILURE);
				}
			}
			for (i = 0; in[i].opcode; i++)
			{
				if (strcmp(array[0], in[i].opcode) == 0)
				{
					in[i].f(&gs.head, count_line);
					break;
				}
			}
			if (!in[i].opcode)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", count_line, array[0]);
				free_stack(gs.head), free_array(array);
				exit(EXIT_FAILURE);
			}
			free_array(array);
		}
		count_line++;
	}
	free_stack(gs.head);
	return (EXIT_SUCCESS);
}
