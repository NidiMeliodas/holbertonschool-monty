#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

int push(stack_t **stack, char *value);
int pall(stack_t **stack);
int pint(stack_t **stack);
int pop(stack_t **stack);
int line_scanner(FILE **file, char **line);
int find_function(stack_t **stack, char *command, char *value);
void safequit(stack_t *arrayStack, int code, int line, char *command);

#endif
