#include "monty.h"

/**
 * freeStack - frees a stack
 * @stack: stack to free
 * Return: void
 */
void freeStack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

/**
 * initfonc - initialises the function/command array
 * @structfonc: array to initialise
 * Return: void
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
* main - executes monty file
*@ac: should be 2
*@av: contatins file name
*Return: failure or success
*/


int main(int ac, char **av)
{
	FILE *file;
	char *word;
	char line[256];
	unsigned int linenum = 0, j;
	instruction_t structfonc[10];
	stack_t *head = NULL;

	initfonc(structfonc);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		linenum++;
		word = strtok(line, " \n");
		for (j = 0; j < 7; j++)
		{
			if (word && strcmp(word, structfonc[j].opcode) == 0)
			{
				structfonc[j].f(&head, linenum);
				break;
			}
		}
		if (word && j >= 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linenum, word);
			exit(EXIT_FAILURE);
		}
	}
	freeStack(&head);
	fclose(file);
	return (EXIT_SUCCESS);
}
