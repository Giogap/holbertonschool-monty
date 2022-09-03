#include "monty.h"

/**
* main - check code
*@argc: value
*@argv: value
*Return: always 0
*/

int main(int argc, char **argv)
{
	FILE *file;
	char *date;
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
		date = strtok(line, " \n");
		for (j = 0; j < 7; j++)
		{
			if (date && strcmp(date, structfonc[j].opcode) == 0)
			{
				structfonc[j].f(&head, linenum);
				break;
			}
		}
		if (date && j >= 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", linenum, date);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
