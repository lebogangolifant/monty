#include "monty.h"

/**
 * pop - Remove the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the instruction being executed.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
