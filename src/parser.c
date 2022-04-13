/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 18:09:58 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/13 14:56:26 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_array(int argc, char **argv)
{
	char	**arr;
	int		i;

	if (argc < 1 || !argv)
		return (NULL);
	arr = malloc(sizeof(char *) * argc);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < argc - 1)
    {
		arr[i] = ft_strdup(argv[i]);
        i++;
    }
	arr[i] = NULL;
	return (arr);
}

char	**get_inp(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else if (argc > 2)
		return (fill_array(argc, &(argv[1])));
	return (NULL);
}
