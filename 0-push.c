#include "monty.h"

/**
 * push - agrega un nodo al inicio de la lista
 * @pila: es el apuntador que apunta al primer nodo de la lista
 * @line_number: linea de la lista
 */

void push(stack_t **pila, unsigned int line_number)
{
	stack_t *newNode;

	/* crear el nuevo nodo */
	newNode = malloc(sizeof(stack_t));
	newNode->n = line_number;

	/* añadimos la pila a continuaciòn al nuevo nodo */
	newNode->next = *pila;

	/* ahora el comienzo de nuestra pila es un nuevo nodo */
	*pila = newNode;
}
