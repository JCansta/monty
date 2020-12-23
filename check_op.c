#include "monty.h"
/**
 * check_op - check the string
 * @line: the string with the commands
 * @head: head of the structure
 * @n_line: line of the file
 */
void check_op(char *line, stack_t **head, int n_line)
{
	char *opcode;


	opcode = strtok(line, " ,!¡¿?\'\"\n\t");
	varg.p_number_str = strtok(NULL, " ,!¡¿?\'\"\n\t");
	if (opcode == NULL)
		return;
	(*find_operator)(opcode);
	if (varg.func_op == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n_line, opcode);
		exit(EXIT_FAILURE);
	}
	if (varg.p_number_str != NULL)
		varg.p_number = check_digit(varg.p_number_str, n_line);
	varg.func_op(head, n_line);
}
