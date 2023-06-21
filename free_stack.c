#include "monty.h"

/**
 * free_stack - Frees all nodes in a stack and sets the stack pointer to NULL.
 * @stack: A double pointer to the stack's head.
 */

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
