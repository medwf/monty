#include "monty.h"

/**
 * check_number - a function that check number
 * @number: a string of numbers
 * Return: 1 on Success or 0
 */
int check_number(char *number)
{
	int i = 0;

	if (atoi(number) <= 0)
		i = 1;

	while (number[i])
	{
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	gs.int_to_push = atoi(number);
	return (1);
}
/**
 * is_open - a function that check if file exist or not
 * @file_name: the name of file.
 * Return: a pointer that open file or
 *             EXIT_FAILURE
 */
void is_open(char *file_name)
{
	gs.file = fopen(file_name, "r");
	if (!gs.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}
/**
 * dte_space - delete wait space from stored (input string)
 *@str: pointers to stored.
 */
void dte_space(char *str)
{
	int i = 0, j = 0;

	while ((*(str + i) == ' ' || *(str + i) == '\t') && *(str + i))
		i++;
	while (*(str + i) && *(str + j))
	{
		*(str + j) = *(str + i);
		i++;
		j++;
	}
	*(str + j) = '\0';
}

/**
 * divide_arg - a function that divied and delete space
 *                            a long sting to argument in av.
 * @line: a pointer to structure.
 * Return: a double pointers.
 */
char **divide_arg(char *line)
{
	int num_token = 0;
	char *token;

	dte_space(line);
	if (strlen(line))
	{
		gs.array = malloc(sizeof(char *) * 2);
		gs.array[0] = NULL;
		gs.array[1] = NULL;

		token = strtok(line, " \t\n");
		while (token && num_token < 2)
		{
			if (num_token == 0)
				gs.array = _realloc(gs.array, sizeof(char *) * 2,
									sizeof(char *) * (num_token + 2));
			if (num_token)
				gs.array = _realloc(gs.array, sizeof(char *) * ((num_token - 1) + 2),
									sizeof(char *) * (num_token + 2));
			if (!gs.array)
			{
				free_array(), free_stack();
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			gs.array[num_token] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(gs.array[num_token++], token);
			token = strtok(NULL, " \t\n");
		}
		gs.array[num_token] = NULL;
	}
	return (NULL);
}
/**
 * process - a function that check process
 * @line_number: line number.
 */
void process(unsigned int line_number)
{
	int i;
	instruction_t in[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{NULL, NULL},
	};

	for (i = 0; in[i].opcode; i++)
	{
		if (strcmp(gs.array[0], in[i].opcode) == 0)
		{
			in[i].f(&gs.head, line_number);
			break;
		}
	}
	if (!in[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, gs.array[0]);
		free_stack(), free_array();
		exit(EXIT_FAILURE);
	}
	free_array();
}
