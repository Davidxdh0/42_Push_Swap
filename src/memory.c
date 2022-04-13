/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 14:59:28 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/13 14:59:49 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	free_exit(char **mat)
{
	free_mat(mat);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(-1);
}
