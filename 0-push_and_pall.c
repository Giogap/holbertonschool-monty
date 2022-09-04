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
	structfonc[2].opcode = "pint";
	structfonc[2].f = pint;
	structfonc[3].opcode = "pop";
	structfonc[3].f = pop;
	structfonc[4].opcode = "add";
	structfonc[4].f = add;
	structfonc[5].opcode = "nop";
	structfonc[5].f = nop;
	structfonc[6].opcode = "swap";
	structfonc[6].f = swap;

}

/**
 * push - agrega un nodo al inicio de la lista
 * @pila: es el apuntador que apunta al primer nodo de la lista
 * @line_number: linea de la lista
 */

void push(stack_t **pila, unsigned int line_number)
{
	stack_t *newNode; /* crea un nuevo nodo */
	stack_t *temp;
	int n;
	char *date;
	char *ptr;

	temp = *pila;
	date = strtok(NULL, " \n");
	if (!date)
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
	newNode = malloc(sizeof(stack_t)); /* create new node */
	newNode->n = n; /* add pila to new node */
	newNode->next = temp;
	newNode->prev = NULL;
	if (temp)
		temp->prev = newNode;
	*pila = newNode; /* start pila in new node */
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

/**
 * pint - check code
 *
 * @numlin: line
 * @pila: the pila change
 *
 */

void pint(stack_t **pila, unsigned int numlin)
{
	if (!(*pila))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", numlin);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*pila)->n);
}
