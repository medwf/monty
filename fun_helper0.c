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
 * @ac: the number of argumant.
 * @file_name: the name of file.
 * Return: a pointer that open file or
 *             EXIT_FAILURE
 */
FILE *is_open(char *file_name)
{
    FILE *file;

    file = fopen(file_name, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    return (file);
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
    char *token, **array = NULL;

    dte_space(line);
    array = malloc(sizeof(char *) * 2);
    array[0] = NULL;
    array[1] = NULL;

    token = strtok(line, " \t\n");
    while (token)
    {
        if (num_token == 0)
            array = _realloc(array, sizeof(char *) * 2,
                             sizeof(char *) * (num_token + 2));
        if (num_token)
            array = _realloc(array, sizeof(char *) * ((num_token - 1) + 2),
                             sizeof(char *) * (num_token + 2));
        if (!array)
        {
            free_array(array);
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        array[num_token] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(array[num_token++], token);
        token = strtok(NULL, " \t\n");
    }
    array[num_token] = NULL;
    return (array);
}