#include "monty.h"
#include <stdio.h>
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
    char line[1024];
    int L = 0;

    if (argc != 2)
    {
        perror("USAGE: monty file");
        return (1);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Error open file");
        return (1);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        L++;
        printf("%d --> %s", L, line);
    }
    /*if (!rd)
    {
        perror("Error Can't read from file");
        fclose(file);
        return (1);
    }*/

    fclose(file);
    return (0);
}