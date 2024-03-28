#include "monty.h"
#include <ctype.h>

/**
 * pop - Pushes an element onto the stack.
 *
 * @arrayStack: Pointer to the top of the stack.
 * Return: 1 on success, 0 on failure.
 */
int pop(stack_t **arrayStack)
{
	stack_t *tmp;

	if (*arrayStack == NULL)
		return (4);

	if ((*arrayStack)->next)
	{
		tmp = *arrayStack;
		*arrayStack = (*arrayStack)->next;
		free(tmp);
		return (1);
	}
	free(*arrayStack);
	*arrayStack = NULL;
	return (1);
}
