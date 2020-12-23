#include "monty.h"
/**
 * all_free - free all the stack
 * @head: the head to free
 */
void all_free(stack_t **head)
{
	stack_t *temp = *head, *next = *head;

	if (temp->next == NULL)
	{
		free(temp);
		return;
	}
	next = next->next;
	while (temp != NULL)
	{
		free(temp);
		temp = next;
		if (next != NULL)
			next = next->next;
	}
}
