/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 16:27:29 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/07 18:51:02 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void two_numbers(t_stack **a)
{
	swap(a, 'a');
}

// 	421, 412, 214,  241, 142
void three_numbers(t_stack **a, int min, int max)
{

	min = 0;

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

void four(t_stack **a, int min, int max)
{
	t_stack *b;
	int flag;

	b = NULL;
	flag = 0;
	while ((*a)->i != min && (*a)->i != max)
		rotate(a);
	if ((*a)->i == max)
		flag = 1;
	pushstack(&b, a, 'b');
	three_numbers(a, minnumber(*a), maxnumber(*a));
	pushstack(a, &b, 'a');
	if (flag == 1)
		rotate(a);
}

void five(t_stack **a, int min)
{
	t_stack *b;
	int countb;

	b = NULL;
	countb = 0;
	while (countb != 2)
	{
		if ((*a)->i == min || (*a)->i == maxnumber(*a) || ((*a)->i == secondminnumber(*a) && countb == 0))
		{
			pushstack(&b, a, 'b');
			min = minnumber(*a);
			countb++;
		}
		else
			rotate(a);
	}
	three_numbers(a, minnumber(*a), maxnumber(*a));
	pushstack(a, &b, 'a');
	if ((*a)->i != minnumber(*a))
		rotate(a);
	pushstack(a, &b, 'a');
	if ((*a)->i != minnumber(*a) && (*a)->i != secondminnumber(*a))
		rotate(a);
	if ((*a)->i != minnumber(*a))
		swap(a, 'a');
	free_list(b);
}

int maxnumber(t_stack *k)
{
	int maxnumber;

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

int minnumber(t_stack *k)
{
	int minnumber;

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

int secondminnumber(t_stack *k)
{
	int minnumbers;
	int lowest;

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
//radix is leeg in het begin
//radix wordth ingevuld met index ipv nummers.
void index_numbers(t_stack **radix, t_stack *a)
{
	t_stack *temp_a;
	t_stack *top_stack;
	int bigger_than;

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
			break;
		}
		listadd_back(radix, temp_a);
		a = a->next;
	}
}

void radix(t_stack **a, t_stack **b)
{
	int bit_place;
	int len;

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
				break;
			len--;
		}
		while (*b)
			pushstack(a, b, 'a');
		bit_place <<= 1;
		//printf("bitplace = %d\n", bit_place);
	}
}

void sort_many(t_stack **a, t_stack **b)
{
	t_stack *radix_stack;

	radix_stack = NULL;
	index_numbers(&radix_stack, *a);
	radix(&radix_stack, b);
	free_list(radix_stack);
}

void sort(t_stack **a, t_stack **b)
{
	int len;
	int min;
	int max;

	len = list_len(*a);
	min = minnumber(*a);
	max = maxnumber(*a);
	if (len == 2)
		two_numbers(a);
	else if (len == 3)
		three_numbers(a, min, max);
	else if (len == 4)
		four(a, min, max);
	else if (len == 5)
		five(a, min);
	else
		sort_many(a, b);
	// printlist(*a);
}