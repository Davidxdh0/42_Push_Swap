/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 18:09:58 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/07 12:22:12 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h> 
#include <stddef.h>

int	ft_isdigit(int argc, char *str)
{
    int i;
    
    i = 1;
    while (str[i])
    {
        if (atoi(argv[i]) > INT_MAX || atoi(argv[i]) < INT_MIN)
            return (0);
    }
	return (1);
}

int	ft_isint(int argc, char *str)
{
    int i;
    
    i = 0;
    while (i <= argc)
    {
        i++;
        printf("int = %d\n", atoi(argv[i]));
        if (atoi(argv[i]) > INT_MAX || atoi(argv[i]) < INT_MIN)
            return (0);
        i++;
    }
	return (1);
}

int	ft_dupl(int argc, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int    ft_error(int argc, char **argv)
{
    int i;
    i = 1;
    if (argc < 2)
        return (0); 
    while (i < argc)
    {
        if (ft_isint(argc, argv[i]) || ft_dupl(argc, argv[i]) || ft_isdigit(argc, argv[i])))
        {
            printf("ft_error\n");
            return (1);
        }
        i++;
    }
    return (0);
}


int main(int argc, char **argv)
{   
    printf("argc = %d\n", argc);
    if (ft_error(argc, argv) == 1)
        return (0);
    else
         write(1, "geen error\n", 11);
    return (1);
}