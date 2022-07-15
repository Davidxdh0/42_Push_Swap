/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:23:40 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/07/15 13:28:20 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minnumber(t_stack *k)
{
	int	minnumber;

	minnumber = k->i;
	while (k)
	{
		if (minnumber <= k->i)
			k = k->next;
		else
			minnumber = k->i;
	}
	return (minnumber);
}

int	maxnumber(t_stack *k)
{
	int	maxnumber;

	maxnumber = k->i;
	while (k)
	{
		if (maxnumber >= k->i)
			k = k->next;
		else
			maxnumber = k->i;
	}
	return (maxnumber);
}

int	secondmin(t_stack *k)
{
	int	minnumbers;
	int	lowest;

	lowest = minnumber(k);
	minnumbers = k->i;
	while (k)
	{
		if (minnumbers <= k->i || lowest == k->i)
			k = k->next;
		else
			minnumbers = k->i;
	}
	return (minnumbers);
}
