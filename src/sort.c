/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 16:27:29 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/14 17:55:58 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(t_stack *a, t_stack *b, int len)
{
    while (!check_sorted(a))
    {
        if (len <= 3)
            b = NULL;
         //sort_three();
        else if (len == 4)
            b = NULL;
            //sort_four();
        else if (len == 5)
            b = NULL;
            //sort_five();
        else if (len <= 100)
            b = NULL;
            //sort_hundred()
        else if (len <= 500)
            b = NULL;
            //sort_five_hunded()
        else
            b = NULL;
            //sort_lots()
    }
    len = 1;
    b = NULL;
    a = NULL;
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