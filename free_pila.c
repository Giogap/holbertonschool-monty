#include "monty.h"

/**
 * free_pila - check code
 * @pila: apuntador al siguiento nodo de la lista
 */

void free_pila(stack_t **pila)
{
	stack_t *temp;

	while (*pila != NULL)
	{
		temp = *pila;
		*pila = (*pila)->next;
		free(temp);
	}
}
