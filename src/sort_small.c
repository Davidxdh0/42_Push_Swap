/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:30:06 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/10 11:33:39 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers(t_stack **a)
{
	swap(a, 'a');
}

// 	421, 412, 214,  241, 142
void	three_numbers(t_stack **a, int max)
{
	while (!check_sorted(a))
	{
		if ((*a)->i == max)
			rotate(a);
		else if ((*a)->i > (*a)->next->i)
			swap(a, 'a');
		else
			reverse_rotate(a);
	}
}

void	four(t_stack **a, int min, int max)
{
	t_stack	*b;
	int		flag;

	b = NULL;
	flag = 0;
	while ((*a)->i != min && (*a)->i != max)
		rotate(a);
	if ((*a)->i == max)
		flag = 1;
	pushstack(&b, a, 'b');
	three_numbers(a, maxnumber(*a));
	pushstack(a, &b, 'a');
	if (flag == 1)
		rotate(a);
}

void	five(t_stack **a, int mi)
{
	t_stack	*b;
	int		i;

	b = NULL;
	i = 0;
	while (i != 2)
	{
		if ((*a)->i == mi || (*a)->i == m(*a) || ((*a)->i == sm(*a) && i == 0))
		{
			pushstack(&b, a, 'b');
			mi = minnumber(*a);
			i++;
		}
		else
			rotate(a);
	}
	three_numbers(a, maxnumber(*a));
	pushstack(a, &b, 'a');
	if ((*a)->i != minnumber(*a))
		rotate(a);
	pushstack(a, &b, 'a');
	if ((*a)->i != minnumber(*a) && (*a)->i != sm(*a))
		rotate(a);
	if ((*a)->i != minnumber(*a))
		swap(a, 'a');
}
