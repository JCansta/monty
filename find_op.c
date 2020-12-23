#include "monty.h"
/**
 * find_operator - find in a structura if a commands exist
 * @str: the command
 */
void find_operator(char *str)
{
	instruction_t forms[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{NULL, NULL}
	};
	int i = 0;

	while (strcmp(forms[i].opcode, str) && forms[i].opcode != NULL)
		i++;
	varg.func_op = forms[i].f;
}
