/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 17:06:06 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/02 18:47:11 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push from stack src to stack dest
void	pushstack(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = NULL;
	if ((*src)->next)
	{
		tmp = (*src)->next;
		tmp->previous = NULL;
	}
	if (dest && *dest)
		(*dest)->previous = *src;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
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
	printf("rotated\n");
}

void reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *last;
	printf("reverse rotated\n");
	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = list_last(*stack);
	list_last(*stack)->previous->next = NULL;
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	tmp->previous = *stack;
}

void swap(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	printf("swap\n");
}

// pa(push a): Take the first element at the top of b and put it at the top of a.
// Do nothing ifbis empty.

// pb(push b): Take the first element at the top ofaand put it at the top ofb.
// Do nothing ifais empty.

// ra(rotate a): Shift up all elements of stackaby 1.
// The first element becomes the last one.

// rb(rotate b): Shift up all elements of stackbby 1.
// The first element becomes the last one.

// rr:raandrbat the same time.