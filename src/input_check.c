/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 11:24:57 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/05/18 12:31:47 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *arg)
{
    int i;
    int k;

    i = 0;
    k = ft_strlen(arg);
	if (arg[0] == '-' && arg[1])
		i++;
	while (ft_isdigit(arg[i]))
		i++;
    if (!ft_isdigit(arg[i]) && i < k)
	{
         printf("!ft_isnumber\n");
    	return (0);
	}
	return (1);
}

int	ft_isint(char *arg)
{
    if ((atol(arg) < -2147483648) || (atol(arg) > 2147483647))
    {
        printf("!ft_isint\n");
        return (1);
    }
	return (0);
}

int	ft_dupl(char **arg)
{
	int	i;
	int	j;
    size_t k; 

	i = 0;
	while (arg[i])
	{
		j = i + 1;
        k = ft_strlen(arg[i]);
		while (arg[j])
		{
            if (ft_strlen(arg[j]) > k)
                k = ft_strlen(arg[j]);
			if (ft_strncmp(arg[i], arg[j], k) == 0)
            {
                printf("!ft_dupl\n");
                return (0);
            }
            j++;
		}
        i++;
	}
	return (1);
}

int    ft_error(char **arg)
{
    int i;
    
    i = 0;
    while (arg[i])
    {
        if (ft_isint(arg[i]) || !ft_dupl(arg) || !ft_isnumber(arg[i]))
        {
            printf("!ft_error\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int     check_sorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->i > stack->next->i)
        {
            printf("!check_sorted\n");
            return (0);
        }
        stack = stack->next;
    }
    printf("check_sorted\n");
    return (1);
}
