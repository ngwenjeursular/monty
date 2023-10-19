#include "monty.h"

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fp;
	char *line = NULL;
	unsigned int line_number;
	char opcode[BUFSIZ], arg[BUFSIZ];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = read_opcode(fp);
		if (line == NULL)
			break;
		line_number = get_line_number(fp);
		if (sscanf(line, "%s %s", opcode, arg) == 2 && strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number, arg);
		}
		else if (strcmp(line, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			exit(EXIT_FAILURE);
		}
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
	}
	fclose(fp);
	return (0);
}
