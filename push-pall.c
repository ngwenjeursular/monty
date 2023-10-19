#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#define  _POSIX_C_SOURCE 200809L

/**
 * push - adds an element to the stack.
 * @stack: double pointer to the stack
 * @line_no: the line_no
 * @arg: argument
 */
void push(stack_t **stack, unsigned int line_no, char *arg)
{
	int n;
	stack_t *new_node;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: missing argument for push\n", line_no);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	if (n == 0 && arg[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}


/**
 * pall - displays values on the stack, starting from the top of the stack.
 * @stack: double pointer to the stack
 */
void pall(stack_t **stack)
{
	stack_t *node;

	if (stack_empty(*stack))
	{
		return;
	}

	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * read_opcode - Read an opcode from a file
 * @fp: A pointer to the file to read from
 *
 * Return: A pointer to the read opcode, or NULL on failure or EOF
 */
char *read_opcode(FILE *fp)
{
	char line[BUFSIZ];
	char *token;

	if (fgets(line, BUFSIZ, fp) == NULL)
	{
		return (NULL);
	}

	line[strcspn(line, "\n")] = '\0';

	token = line;

	return (token);
}


/**
 * get_line_number - Count the number of lines in a file
 * @fp: File pointer to the input file
 *
 * Return: Number of lines in the file
 */
unsigned int get_line_number(FILE *fp)
{
	unsigned int line_number = 0;
	int current_char;
	int previous_char = '\n'; /* Initialize to '\n' to count the first line */

	while ((current_char = fgetc(fp)) != EOF)
	{
		if (current_char == '\n')
		{
			line_number++;
		}
		previous_char = current_char;
	}

	/* If the file doesn't end with a newline, consider the last line */
	if (previous_char != '\n')
	{
		line_number++;
	}

	rewind(fp); /* Reset the file pointer to the beginning of the file */

	return (line_number);
}
/**
 * stack_empty - checks if if the stack is empty
 * @stack: pointer to the stack
 *
 * Return: an int
 */
int stack_empty(stack_t *stack)
{
	return (stack == NULL);
}
