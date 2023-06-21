#include "monty.h"

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number where the opcode is encountered.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
