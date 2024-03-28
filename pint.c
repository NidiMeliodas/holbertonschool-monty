#include "monty.h"
#include <ctype.h>

/**
 * pint - Pushes an element onto the stack.
 *
 * @arrayStack: Pointer to the top of the stack.
 * Return: 1 on success, 0 on failure.
 */
int pint(stack_t **arrayStack)
{
	stack_t *current;

	if (*arrayStack == NULL)
		return (3);

	current = *arrayStack;
	printf("%i\n", current->n);

	return (1);
}
