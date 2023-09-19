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
 * Return:
 */
int main(int argc, char **argv)
{
    char line[1024], **array = NULL;
    unsigned int i, count_line = 1;
    instruction_t in[] = {
        {"push", hundle_push},
        {NULL, NULL},
    };

    if (argc == 2)
        gs.file = is_open(argv[1]);
    else
        print_error("USAGE: monty file");

    gs.head = NULL;
    while (fgets(line, sizeof(line), gs.file) != NULL)
    {
        array = divide_arg(line);
        if (strcmp(array[0], "push") == 0)
        {
            if (!(array[1] && check_number(array[1])))
            {
                fprintf(stderr, "L%d: usage: push integer\n", count_line);
                fclose(gs.file);
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
        free_array(array), count_line++;
    }

    fclose(gs.file);
    return (EXIT_SUCCESS);
}