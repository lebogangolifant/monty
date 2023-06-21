#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number where the opcode is encountered.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	stack_t *new_node;

	arg = (char *)strtok(NULL, " \t\n");
	if (!arg || !isdigit((unsigned char)arg[0]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	} else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}
