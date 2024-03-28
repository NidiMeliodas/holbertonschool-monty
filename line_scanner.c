#include "monty.h"

/**
 * line_scanner - Scan line of file and ex find_function for command.
 *
 * @file: pointer to the file to be scanned
 * @line: number of line.
 * Return: Always 0, indicating the completion of line scanning.
 */
int line_scanner(FILE **file, char **line)
{
	char *token = NULL;
	size_t len = 0;
	char *command = NULL;
	stack_t *arrayStack = NULL;
	int ff;
	int line_num = 0;

	while (getline(line, &len, *file) > 0)
	{
		token = NULL;
		command = strtok(*line, " \t\n\r");
		len++;

		line_num++;
		if (!command || strlen(command) == 0)
			continue;

		token = strtok(NULL, " \t\n\r");
		while (token && strlen(token) == 0)
			token = strtok(NULL, " \t\n\r");
		ff = find_function(&arrayStack, command, token);
		if (ff != 1)
		{
			fclose(*file);
			safequit(arrayStack, ff, line_num, command);
		}
		free(*line);
		*line = NULL;
	}
	safequit(arrayStack, 1, line_num, NULL);
	return (0);
}

/**
 * safequit - Safe quit the program.
 *
 * @arrayStack: array of stack
 * @code: exit code
 * @line: line command exit
 * @command: command exit (maybe empty)
 */
void safequit(stack_t *arrayStack, int code, int line, char *command)
{
	stack_t *temp;

	while (arrayStack != NULL)
	{
		temp = arrayStack;
		arrayStack = arrayStack->next;
		free(temp);
	}

	if (code == 0)
		dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line);
	if (code == 1)
		return;
	if (code == 2)
		dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", line, command);
	if (code == 3)
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line);
	if (code == 4)
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line);
	free(command);
	exit(EXIT_FAILURE);
}
