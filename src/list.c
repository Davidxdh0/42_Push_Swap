/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 10:35:45 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/10 13:39:14 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*list_new(int i)
{
	t_stack	*list_new;

	list_new = malloc(sizeof(t_stack));
	if (!list_new)
		return (NULL);
	list_new->i = i;
	list_new->previous = NULL;
	list_new->next = NULL;
	return (list_new);
}

int	list_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack	*list_last(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	listadd_back(t_stack **stack, t_stack *current)
{
	t_stack	*last;

	last = list_last(*stack);
	if (last != NULL)
	{
		last->next = current;
		current->previous = last;
	}
	else
		*stack = current;
}

void	printlist(t_stack *a)
{
	while (a != NULL)
	{
		printf("%d ", a->i);
		a = a->next;
	}
	printf("\n");
}
