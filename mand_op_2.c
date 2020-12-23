#include "monty.h"
/**
 * swap_op - swap first two
 * @stack: head of the stack
 * @line_number: number of the line
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp2;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp->prev = temp->next;
	temp->next = temp->next->next;
	temp2->prev = NULL;
	temp2->next = temp;
	*stack = temp2;
}
/**
 * add_op - add the last two
 * @stack: head of the stack
 * @line_number: number of the line
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->n + temp->next->n;
	*stack = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
/**
 * nop_op - what are you looking at, this do nothing
 * @stack: head of the stack
 * @line_number: number of the line
 */
void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
