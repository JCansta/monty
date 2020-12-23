#include "monty.h"
/**
 * check_digit - check if a string is digit
 * @number: the string of the digit
 * @n_line: number of the line
 * Return: the number in int
 */
int check_digit(char *number, int n_line)
{
	int i;

	for (i = 0; number[i] != '\0'; i++)
	{
		if (number[i] < '0' && number[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", n_line);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(number));
}
