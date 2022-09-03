#include "monty.h"

/**
 * push - agrega un nodo al inicio de la lista
 * @pila: es el apuntador que apunta al primer nodo de la lista
 * @line_number: linea de la lista
 */

void push(stack_t **pila, unsigned int line_number)
{
	stack_t *newNode;
	int number;
	/*stack_t temp;*/
	char *line;
	char *ptr;

	line = strtok(NULL, "\n");
	if(!line)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = strtol(line, &ptr, 10);
	if (ptr[0] != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* crear el nuevo nodo */
	newNode = malloc(sizeof(stack_t));
	newNode->n = number;

	/* añadimos la pila a continuaciòn al nuevo nodo */
	newNode->next = *pila;

	/* ahora el comienzo de nuestra pila es un nuevo nodo */
	*pila = newNode;
}

void pall(stack_t **pila, unsigned int line_number)
{
	stack_t *tmp = *pila;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	if (0)
		printf("%d", line_number);
}
