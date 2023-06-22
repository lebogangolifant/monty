#include "monty.h"

/**
 * process_file - Process the Monty bytecode file.
 * @file: Pointer to the file to process.
 */

void process_file(FILE *file)
{
	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;
	char *opcode;
	void (*fn)(stack_t **, unsigned int);
	instruction_t *instruction;
	stack_t *stack = NULL;

	while (fgets(buffer, BUFFER_SIZE, file))
	{
		line_number++;
		opcode = strtok(buffer, " \t\n");
		if (!opcode)
			continue;

		fn = NULL;
		instruction = get_instruction(opcode);
		if (instruction)
			fn = instruction->f;

		if (!fn)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcode);
			fclose(file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}

		fn(&stack, line_number);
	}

	fclose(file);
	free_stack(&stack);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: On success, returns EXIT_SUCCESS, On failure, returns EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_file(file);

	return (EXIT_SUCCESS);
}
