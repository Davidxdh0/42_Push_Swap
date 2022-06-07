/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 16:27:29 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/07 19:35:10 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//radix is leeg in het begin
//radix wordth ingevuld met index ipv nummers.
void	index_numbers(t_stack **radix, t_stack *a)
{
	t_stack	*temp_a;
	t_stack	*top_stack;
	int		bigger_than;

	top_stack = a;
	while (a)
	{
		temp_a = top_stack;
		bigger_than = 0;
		while (temp_a)
		{
			if (a->i > temp_a->i)
				bigger_than++;
			temp_a = temp_a->next;
		}
		temp_a = list_new(bigger_than);
		if (!temp_a)
		{
			free_list(temp_a);
			free_list(top_stack);
			break ;
		}
		listadd_back(radix, temp_a);
		a = a->next;
	}
}

void	radix(t_stack **a, t_stack **b)
{
	int	bit_place;
	int	len;

	bit_place = 0b00000001;
	while (!check_sorted(a))
	{
		len = list_len(*a);
		while (len)
		{
			if (((*a)->i & bit_place))
				rotate(a);
			else
				pushstack(b, a, 'b');
			if (check_sorted(a))
				break ;
			len--;
		}
		while (*b)
			pushstack(a, b, 'a');
		bit_place <<= 1;
	}
}

void	sort_many(t_stack **a, t_stack **b)
{
	t_stack	*radix_stack;

	radix_stack = NULL;
	index_numbers(&radix_stack, *a);
	radix(&radix_stack, b);
	free_list(radix_stack);
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;
	int	min;
	int	max;

	len = list_len(*a);
	min = minnumber(*a);
	max = maxnumber(*a);
	if (len == 2)
		two_numbers(a);
	else if (len == 3)
		three_numbers(a, max);
	else if (len == 4)
		four(a, min, max);
	else if (len == 5)
		five(a, min);
	else
		sort_many(a, b);
}
