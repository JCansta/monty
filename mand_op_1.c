#include "monty.h"
/**
 * push_op - push a new structure
 * @stack: head of the stack
 * @line_number: number of the line
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (varg.p_number_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		*stack = new;
		new->n = varg.p_number;
		new->prev = NULL;
		new->next = NULL;
		return;
	}
	new->n = varg.p_number;
	new->next = *stack;
	new->prev = NULL;
	new->next->prev = new;
	*stack = new;
}
/**
 * pall_op - print all the stack
 * @stack: head of the stack
 * @line_number: number of the line
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
/**
* pint_op - print the top
* @stack: head of the stack
* @line_number: number of the line
*/
void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
* pop_op - removes the top element
* @stack: head of the stack
* @line_number: number of the line
*/
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	free(temp);
}
