/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 18:09:58 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/17 19:40:46 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h> 

int	splitted(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**splitarr;

	i = 0;
	j = 0;
	k = 0;
	while (i < argc - 1)
	{
		splitarr = ft_split(argv[i], ' ');
		j = 0;
		while (splitarr[j])
		{
			j++;
			k++;
		}
		i++;
		free_arr(splitarr);
	}
	return (k);
}

char	**fill_array(int argc, char **argv)
{
	char	**arr;
	char	**splitarr;
	int		i;
	int		j;
	int		k;

	arr = malloc(sizeof(char *) * splitted(argc, argv) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (i < argc - 1)
	{
		splitarr = ft_split(argv[i], ' ');
		j = 0;
		while (splitarr[j])
		{
			arr[k++] = ft_strdup(splitarr[j]);
			j++;
		}
		i++;
		free_arr(splitarr);
	}
	arr[k] = NULL;
	return (arr);
}

char	**get_inp(int argc, char **argv)
{
	int	i;

	i = 1;
	if (i < argc - 1)
	{
		while (argv[i])
		{	
			if (argv[i][0] == '\0')
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			i++;
		}
	}
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else if (argc > 2)
		return (fill_array(argc, &argv[1]));
	return (NULL);
}
