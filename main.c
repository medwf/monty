#include "main.h"
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
    char *line;
    size_t len, read = 0;

    file = fopen(argv[1], "r");
    if (file == NULL)
        perror("Error open file"), return (1);

    read = getline(&line, &len, file);
    if (read == -1)
        perror("Error Can't read from file"), return (1);

    fclose(file);
    return (0);
}