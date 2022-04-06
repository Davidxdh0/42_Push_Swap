/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 18:09:58 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/06 14:20:07 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include <limits.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isint(long c)
{
	return (c >= INT_MIN && c <= INT_MAX);
}

ft_dupl(char **argv, argc)
{
    char    *temp;
    int     i;
    int     j;

    i = 0;
    temp = malloc(sizeof(int) * argc)
    if (!temp)
        return (NULL);
    temp[i] = argv[i];
    while[argv[i]]
    {
        j = 0
        while(argv[i] != temp[j] && temp[j])
        {
            j++;
            if (argv[i] == temp[j])
                return (0);
        }
        temp[i] = argv[i]; 
        i++;
    }
    return (1);
}

int    ft_error(int argc, char **argv)
{
    int i;
    i = 0;
    if (argc <= 1)
        return ; 
    while (argc > i)
    {
        if (!ft_isdigit(argv[i] || !ft_isint(argv[i]) || ft_dupl(argv[i], argc))
        {
            write(3, "Error\n", 6);
            return (1);
        }
        i++;
    }
    return (0);
}




int			main(int argc, char **argv)
{   
    if (ft_error(argc, **argv) == 1)
        exit();
    
}