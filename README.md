
# Monty Bytecode Interpreter

The Monty Bytecode Interpreter is a program that reads and executes Monty bytecode files. 

## Usage

To run the Monty Bytecode Interpreter, use the following command:

```
./monty file
```

where `file` is the path to the Monty bytecode file you want to execute.

## Instructions

The Monty bytecode language supports the following instructions:

- `push <value>`: Pushes an integer value to the stack.
- `pall`: Prints all the values on the stack, starting from the top.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element of the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: Does nothing.
- `...` (more instructions)

Additional instructions may be added to the language in the future.

## Example Monty Bytecode File

Here is an example Monty bytecode file that adds two numbers:

```
push 1$
push 2$
push 3$
pall$
```

Running this file with the Monty Bytecode Interpreter will output:

```
3
2
1
```

## Error Handling

The Monty Bytecode Interpreter includes error handling for the following cases:

- Invalid instructions: If an unknown instruction is encountered, an error message will be displayed with the line number and the unknown instruction. The interpreter will exit with a failure status.
- File opening failure: If the specified bytecode file cannot be opened, an error message will be displayed. The interpreter will exit with a failure status.

## Implementation Details

The Monty Bytecode Interpreter is implemented in C programming language. The main functionality is contained in the ` process_file.c` file. Additional helper functions and data structures are defined in separate files.

## Building the Interpreter

To build the Monty Bytecode Interpreter, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

This will compile all the necessary source files and generate an executable named `monty`.



