#include "monty.h"
/**
 * free_array - a function free argumment.
 * @array: a pointer to structure input
 */
void free_array(char **array)
{
	int i = 0;

	/* if av == NULL dont free and return*/
	if (!array)
		return;
	/* free av */
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
/**
 * _realloc - reallocates a memory block using malloc and free.
 *@old_size: is the size, in bytes, of the allocated space for ptr.
 *@new_size: is the new size, in bytes of the new memory block.
 *@ptr:  is a pointer to the memory previously allocated.
 *Return: NULL or pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = 0;
	char *ptr_new;
	char *ptr_old;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	ptr_new = malloc(new_size);
	if (ptr_new == NULL)
		return (NULL);

	ptr_old = ptr;
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			ptr_new[i] = ptr_old[i];
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			ptr_new[i] = ptr_old[i];
	}
	free(ptr);
	return (ptr_new);
}
/**
 * free_stack - free stack
 * @h: a pointer to linked list
 */
void free_stack(stack_t *h)
{
	if (h)
	{
		while (h->next)
		{
			h = h->next;
			free(h->prev);
		}
		free(h);
	}
}
