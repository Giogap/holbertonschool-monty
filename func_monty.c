#include "monty.h"

/**
 * push - pushes element to the stack
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new;
	stack_t *tmp;
	char *word;
	char *ptr;

	tmp = *stack;
	word = strtok(NULL, " \n");
	if (!word)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = strtol(word, &ptr, 10);
	if (ptr[0] != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = num;
	new->next = tmp;
	new->prev = NULL;
	if (tmp)
		tmp->prev = new;
	*stack = new;
}

/**
 * pall - prints all ellements in stack
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	if (0)
		printf("%d", line_number);
}
/**
 * pint - prints top of stack
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
