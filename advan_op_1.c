#include "monty.h"
/**
 *sub_op - removes the top elemen
 *@stack: head of the stack
 *@line_number: number of the line
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n - temp->n;
	*stack = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
/**
 *div_op - removes the top elemen
 *@stack: head of the stack
 *@line_number: number of the line
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n / temp->n;
	*stack = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
/**
 *mul_op - removes the top elemen
 *@stack: head of the stack
 *@line_number: number of the line
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n * temp->n;
	*stack = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
/**
 *mod_op - removes the top elemen
 *@stack: head of the stack
 *@line_number: number of the line
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->next->n = temp->next->n % temp->n;
	*stack = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
