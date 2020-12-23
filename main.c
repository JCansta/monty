#include "monty.h"
/**
 * main - main function
 * @argc: number of parameters
 * @argv: the parameters
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *m;
	stack_t *head = NULL;
	char line[256];
	int n_line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m = fopen(argv[1], "r");
	if (m == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), m))
	{
		check_op(line, &head, n_line);
		n_line++;
	}
	all_free(&head);

	return (0);
}
