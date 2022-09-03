#include "monty.h"

/**
 * initfonc - initialization array
 * @structfonc: array to initialise
 */

void initfonc(instruction_t *structfonc)
{
	structfonc[0].opcode = "push";
	structfonc[0].f = push;
	structfonc[1].opcode = "pall";
	structfonc[1].f = pall;
}

/**
 * push - agrega un nodo al inicio de la lista
 * @pila: es el apuntador que apunta al primer nodo de la lista
 * @line_number: linea de la lista
 */

void push(stack_t **pila, unsigned int line_number)
{
	stack_t *newNode;
	int n;
	stack_t *temp;
	char *date;
	char *ptr;

	temp = *pila;
	date = strtok(NULL, "\n");
	if(!date)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = strtol(date, &ptr, 10);
	if (ptr[0] != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* crear el nuevo nodo */
	newNode = malloc(sizeof(stack_t));

	/* añadimos la pila a continuaciòn al nuevo nodo */
	newNode->n = n;
	newNode->next = temp;
	newNode->prev = NULL;
	if (temp)
		temp->prev = newNode;

	/* ahora el comienzo de nuestra pila es un nuevo nodo */
	*pila = newNode;
}

/**
 * pall - check code
 * @pila: es el apuntador que apunta al primer nodo de la lista
 * @line_number: linea de la lista
 */

void pall(stack_t **pila, unsigned int line_number)
{
	stack_t *temp = *pila;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	if (0)
		printf("%d", line_number);
}
