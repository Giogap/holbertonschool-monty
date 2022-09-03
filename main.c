#include "monty.h"

/**
 * initfonc - check code
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
* main - executes monty file
*@ac: should be 2
*@av: contatins file name
*Return: failure or success
*/

int main(int argc, char **argv)
{
	FILE *file;
	char *word;
	char line[256];
	unsigned int linenum = 0, j;
	instruction_t structfonc[10];
	stack_t *head = NULL;

	initfonc(structfonc);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
	fclose(file);
	return (EXIT_SUCCESS);
}
