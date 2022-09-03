#include "monty.h"

/**
 * pop - remove top element of stack
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(tmp);
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
}


/**
 * swap - swaps top 2 elements of stack
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}


/**
 * add - add the top 2 elements of stack
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}


/**
 * nop - does nothing
 *
 * @line_number: line in file "filename"
 * @stack: the stack to change
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	if (0)
		printf("%d%p", line_number, (void *)stack);
}
