#include "monty.h"

/**
 * find_function - Finds the appropriate function to execute.
 * @arrayStack: Double pointer to the stack.
 * @command: The command to be executed.
 * @value: The value to be used with the command.
 *
 * Return: 0 if successful, otherwise returns the function's return value.
 */
int find_function(stack_t **arrayStack, char *command, char *value)
{
	if (strcmp(command, "push") == 0)
		return (push(arrayStack, value));
	if (strcmp(command, "pall") == 0)
		return (pall(arrayStack));
	if (strcmp(command, "pint") == 0)
		return (pint(arrayStack));
	if (strcmp(command, "pop") == 0)
		return (pop(arrayStack));
	return (2);
}
