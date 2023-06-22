#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the instruction.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
