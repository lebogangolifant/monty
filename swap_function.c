#include "monty.h"

/**
 * swap - Swap the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
