/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 18:09:58 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/10 14:42:08 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_array(int argc, char **argv)
{
	char	**arr;
	int		i;

	if (!argv)
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
