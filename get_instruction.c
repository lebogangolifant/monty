#include "monty.h"

/**
 * strdup - Duplicates a string by allocating memory and copying the string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to a newly allocated string.
 */

char *strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
		return (NULL);
	return (memcpy(new_str, str, len));
}

/**
 * create_instruction - Creates an instruction_t struct.
 * @opcode: The opcode of the instruction.
 * @f: The function pointer of the instruction.
 *
 * Return: Pointer to the created instruction_t struct.
 */

instruction_t *create_instruction(char *opcode, void (*f)
		(stack_t **stack, unsigned int line_number))
{
	instruction_t *instruction = malloc(sizeof(instruction_t));

	if (!instruction)
		return (NULL);

	instruction->opcode = strdup(opcode);
	instruction->f = f;
	return (instruction);
}

/**
 * free_instructions - Frees the memory of an array of instruction_t structs.
 * @instructions: The array of instruction_t structs.
 */

void free_instructions(instruction_t *instructions)
{
	int i;

	if (instructions == NULL)
		return;

	for (i = 0; instructions[i].opcode; i++)
	{
		free(instructions[i].opcode);
	}

	free(instructions);
}

/**
 * get_instruction - Retrieves the corresponding instruction
 * for a given opcode.
 * @opcode: The opcode to search for.
 *
 * Return: A pointer to the instruction_t struct.
 */

instruction_t *get_instruction(char *opcode)
{
	int index;

	instruction_t *instructions = malloc(sizeof(instruction_t) * 8);

	if (!instructions)
		return (NULL);

	instructions[0] = *create_instruction("push", push);
	instructions[1] = *create_instruction("pall", pall);
	instructions[2] = *create_instruction("pint", pint);
	instructions[3] = *create_instruction("pop", pop);
	instructions[4] = *create_instruction("swap", swap);
	instructions[5] = *create_instruction("add", add);
	instructions[6] = *create_instruction("nop", nop);
	instructions[7].opcode = NULL;
	instructions[7].f = NULL;

	index = 0;

	while (instructions[index].opcode)
	{
		if (strcmp(instructions[index].opcode, opcode) == 0)
		{
			instruction_t *instruction = create_instruction
				(instructions[index].opcode,
				 instructions[index].f);
			free_instructions(instructions);
			return (instruction);
		}

		index++;
	}

	free_instructions(instructions);
	return (NULL);
}
