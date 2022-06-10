/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 17:06:06 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/10 14:50:47 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push from stack src to stack dest
void	pushstack(t_stack **dest, t_stack **src, char stack)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	(*dest) = tmp;
	if (stack == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

//rotate 
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	(*stack)->next->previous = NULL;
	tmp = list_last(*stack);
	tmp->next = *stack;
	(*stack)->previous = tmp;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = list_last(*stack);
	list_last(*stack)->previous->next = NULL;
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	tmp->previous = *stack;
	write(1, "rra\n", 4);
}

void	swap(t_stack **stack, char stackchar)
{
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	if (stackchar == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}
