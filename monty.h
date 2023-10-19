#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#define  _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Function Prototypes*/
void push(stack_t **stack, unsigned int line_no, char *arg);
void pall(stack_t **stack);
int stack_empty(stack_t *stack);

char *read_opcode(FILE *fp);
unsigned int get_line_number(FILE *fp);
int strcmp(const char *s1, const char *s2);
unsigned int get_line_number(FILE *fp);
int stack_empty(stack_t *stack);

#endif /*MONTY_H*/
