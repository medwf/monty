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
	char line[100];
	unsigned int count_line = 1;

	if (argc == 2)
		is_open(argv[1]);
	else
		print_error("USAGE: monty file");

	gs.head = NULL, gs.array = NULL;
	while (fgets(line, sizeof(line), gs.file) != NULL)
	{
		line[strlen(line) - 1] = '\0', divide_arg(line);
		if (gs.array)
		{
			if (strcmp(gs.array[0], "push") == 0)
			{
				if (!(gs.array[1] && check_number(gs.array[1])))
				{
					fprintf(stderr, "L%d: usage: push integer\n", count_line);
					free_stack(), free_array();
					exit(EXIT_FAILURE);
				}
			}
			process(count_line);
		}
		count_line++;
	}
	free_stack();
	return (EXIT_SUCCESS);
}
