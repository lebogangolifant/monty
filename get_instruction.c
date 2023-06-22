#include <string.h>
#include <stdlib.h>
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
 * get_instruction - Retrieves the corresponding instruction
 * for a given opcode.
 * @opcode: The opcode to search for.
 *
 * Return: A pointer to the instruction_t struct that matches the given
 * opcode,or NULL if no match is found.
 */

instruction_t *get_instruction(char *opcode)
{
	int index = 0;

	instruction_t *instructions = malloc(sizeof(instruction_t) * 5);

	if (!instructions)
		return (NULL);

	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = "pop";
	instructions[3].f = pop;
	instructions[4].opcode = NULL;
	instructions[4].f = NULL;

	while (instructions[index].opcode)
	{
		if (strcmp(instructions[index].opcode, opcode) == 0)
		{
			instruction_t *instruction =
				malloc(sizeof(instruction_t));
			if (!instruction)
			{
				free(instructions);
				return (NULL);
			}
			instruction->opcode =
				strdup(instructions[index].opcode);
			instruction->f = instructions[index].f;
			free(instructions);
			return (instruction);
		}
		index++;
	}
	free(instructions);
	return (NULL);
}
