/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 16:27:29 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/05/18 12:33:08 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    two_numbers(t_stack **a)
{
    rotate(a);
}

void    three_numbers(t_stack *a, t_stack *b)
{
    if (a->i > a->next->i)
        pushstack(&b, &a);
    printlist(b);
}

int     maxnumber(t_stack *k)
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
int	lower_numbers(t_stack **radix, t_stack *origin)
{
	t_stack	*aux;
	t_stack	*first_el;
	int		bigger_than;

	first_el = origin;
	while (origin)
	{
		aux = first_el;
		bigger_than = 0;
		while (aux)
		{
			if (origin->i > aux->i)
				bigger_than++;
			aux = aux->next;
		}
		aux = list_new(bigger_than);
		if (!aux)
			break ;
		listadd_back(radix, aux);
		origin = origin->next;
	}
	if (origin)
	{
		return (1);
	}
	return (0);
}

int	is_lownb_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
			if (stack->next->i - stack->i != 1)
				return (0);
		stack = stack->next;
	}
	return (1);
}


void	radix(t_stack **a, t_stack **b)
{
	int	bit_place;
	int	stack_len;

	bit_place = 0b00000001;
	while (!check_sorted(*a))
	{
		stack_len = list_len(*a);
		while (stack_len)
		{
			if (((*a)->i & bit_place))
				rotate(a);
			else
				pushstack(b, a);
			if (is_lownb_sorted(*a))
				break ;
			stack_len--;
		}
		while (*b)
			pushstack(a, b);
		bit_place <<= 1;
	}
    printlist(*a);
}

void	sort_many(t_stack **a, t_stack **b)
{
	t_stack	*radix_stack;

	radix_stack = NULL;
	if (lower_numbers(&radix_stack, *a))
	{
		free_list(*a);
		free_list(radix_stack);
		exit(-1);
	}
	radix(&radix_stack, b);
	free_list(radix_stack);
}

// void    radix(t_stack *a, t_stack *b)
// {
//     int len_a = list_len(a); 
//     int len_b = list_len(b);

//     len_a += len_b;
// }

void    indexsort(t_stack *a, t_stack *b, int len)
{
    len += 1;
    printlist(b);
    while (a != NULL)
    {
        b->i = a->i;
        a = a->next;
        b = b->next;
    }
    while (b != NULL)
    {
        while (!check_sorted(b))
        {
            if ( b->i > b->next->i)
                b->next->i = b->i;
            else
                b = b->next;
        }
    }
    printlist(b);
}

void    sort(t_stack *a, t_stack *b, int len)
{
    while (!check_sorted(a))
    { 
        if (len == 2)
            two_numbers(&a);
        else if (len == 3)
        {
            three_numbers(a, b);
        }
        else if (len >= 4)
            sort_many(&a, &b);
        else
            b = NULL;
            //sort_lots()
    }
    len = 1;
    b = NULL;
    a = NULL;
	// printlist(a);
	// printlist(b);
}
/*
sort struct. (lelijk)
stack a indexeren
resultaat bitwisen

sort met commandos index (mooi)


pb 
ra
pa

 */