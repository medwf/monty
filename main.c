#include "monty.h"
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
 * Return:
 */
int main(int argc, char **argv)
{
    FILE *file;
    char line[1024], **array = NULL;
    unsigned int i, count_line = 1;

    if (argc == 2)
        file = is_open(argv[1]);
    else
        print_error("USAGE: monty file");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("\nL %d: %s =", count_line, line);
        /* delete space at beggining and divide arg*/
        array = divide_arg(line);
        i = 0;
        while (array[i])
        {
            printf("- arg %d = -> %s", i, array[i]);
            i++;
        }
        free_array(array), count_line++;
    }

    fclose(file);
    return (EXIT_SUCCESS);
}