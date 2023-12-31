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

	gs.head = NULL, gs.array = NULL, gs._switch = 0;
	while (fgets(line, sizeof(line), gs.file) != NULL)
	{
		line[strlen(line) - 1] = '\0', gs.array = divide_arg(line);
		if (gs.array)
		{
			if (strcmp(gs.array[0], "nop") == 0 || gs.array[0][0] == '#')
			{
				free_array(gs.array);
				continue;
			}
			if (strcmp(gs.array[0], "push") == 0)
			{
				if (!(gs.array[1] && check_number(gs.array[1])))
				{
					fprintf(stderr, "L%d: usage: push integer\n", count_line);
					free_stack(gs.head), free_array(gs.array);
					exit(EXIT_FAILURE);
				}
			}
			process(gs.array, count_line);
		}
		count_line++;
	}
	free_stack(gs.head);
	return (EXIT_SUCCESS);
}
