#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_glob_s - pointer functions and number
 * @p_number: the number to push to the structure
 * @func_op: pointer to function
 * @p_number_str: something
 * Description: p_number and his function
 */
typedef struct var_glob_s
{
	int p_number;
	void (*func_op)(stack_t **, unsigned int);
	char *p_number_str;
} var_glob_t;

var_glob_t varg;

/*prototype*/
int main(int argc, char *argv[]);
void check_op(char *line, stack_t **head, int n_line);
void find_operator(char *str);
int check_digit(char *number, int n_line);
void all_free(stack_t **head);

/*operators*/
void push_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void nop_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
#endif
