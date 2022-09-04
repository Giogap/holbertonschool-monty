#include "monty.h"

/**
 * pop - check code
 *
 * @numlin: line in file "filename"
 * @pila: the stack to change
 *
 */
void pop(stack_t **pila, unsigned int numlin)
{
	stack_t *tmp = *pila;

	if (!(*pila))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", numlin);
		exit(EXIT_FAILURE);
	}
	*pila = (*pila)->next;
	free(tmp);
	if (*pila)
	{
		(*pila)->prev = NULL;
	}
}


/**
 * swap - check code
 *
 * @numlin: line in file "filename"
 * @pila: the stack to change
 *
 */
void swap(stack_t **pila, unsigned int numlin)
{
	int n;

	if (!(*pila) || !(*pila)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", numlin);
		exit(EXIT_FAILURE);
	}
	n = (*pila)->n;
	(*pila)->n = (*pila)->next->n;
	(*pila)->next->n = n;
}


/**
 * add - check code
 *
 * @numlin: line in file "filename"
 * @pila: the stack to change
 *
 */
void add(stack_t **pila, unsigned int numlin)
{
	if (!(*pila) || !(*pila)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", numlin);
		exit(EXIT_FAILURE);
	}
	(*pila)->next->n += (*pila)->n;
	pop(pila, numlin);
}


/**
 * nop - does nothing
 *
 * @numlin: line in file "filename"
 * @pila: the stack to change
 *
 */
void nop(stack_t **pila, unsigned int numlin)
{
	if (0)
		printf("%d%p", numlin, (void *)pila);
}
