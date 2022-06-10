/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 11:41:21 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/10 14:41:38 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arg)
{
	int	i;

	i = 0;
	if (!arg)
		return ;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

void	free_list(t_stack *node)
{
	t_stack	*temp;

	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	free_message_exit(char **arg)
{
	free_arr(arg);
	write(1, "Error\n", 6);
	exit(0);
}

t_stack	*a_stack(char **arg)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;
	int		k;

	i = 0;
	a = NULL;
	while (arg[i])
	{
		k = ft_atoi(arg[i]);
		temp = list_new(k);
		if (!temp)
			break ;
		listadd_back(&a, temp);
		i++;
	}
	free_arr(arg);
	return (a);
}

int	main(int argc, char **argv)
{
	char	**arg;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || argc == 2)
		exit(0);
	arg = fill_array(argc, &argv[1]);
	if (ft_error(arg) == 1 || !arg)
		free_message_exit(arg);
	a = a_stack(arg);
	b = NULL;
	if (!check_sorted(&a))
		sort(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
