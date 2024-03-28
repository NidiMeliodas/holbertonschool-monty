#include "monty.h"
#include <ctype.h>

/**
 * push - Pushes an element onto the stack.
 *
 * @arrayStack: Pointer to the top of the stack.
 * @value: String representing the value to be pushed onto the stack.
 * Return: 1 on success, 0 on failure.
 */
int push(stack_t **arrayStack, char *value)
{
	int n;
	int line_num = 0;

	if (!value || strlen(value) == 0)
		return (0);

	for (int i = 0; value[i] != '\0'; i++)
	{
		if (!isdigit(value[i]) && value[i] != '-' && value[i] != '+')
		{
			return (0);
		}
		line_num++;
	}

	n = atoi(value);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (0);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = n;

	if (*arrayStack)
	{
		new_node->next = *arrayStack;
	}
	*arrayStack = new_node;
	return (1);
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 *
 * @arrayStack: Pointer to the top of the stack.
 * Return: Always 0.
 */
int pall(stack_t **arrayStack)
{
	stack_t *current;

	if (arrayStack == NULL)
		return (0);

	current = *arrayStack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return (1);
}
