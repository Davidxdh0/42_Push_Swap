/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 11:41:21 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/13 15:13:23 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
t_stack	*a_stack(char **arg)
{
	t_stack	*a;
	t_stack	*tmp;
	long	num;
	int		i;

	i = -1;
	a = NULL;
	while (arg[++i])
	{
		num = ft_atol(arg[i]);
		if (num < INT_MIN || num > INT_MAX)
			break ;
		tmp = lst_new(num);
		if (!tmp)
			break ;
		lstadd_back(&a, tmp);
	}
	if (arg[i])
	{
		free_lst(a);
		free_exit(arg);
	}
	free_mat(arg);
	return (a);
}

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
void	free_exit(char **arg)
{
	free_arr(arg);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(-1);
}

int main(int argc, char **argv)
{   
    char    **arg;
    t_stack *a;
    t_stack *b;
    arg = get_inp(argc, argv);
    if (ft_error(arg) == 1 || !arg)
        write(1, "\n1\n", 2);
    else
        write(1, "geen error\n", 11);
    a = a_stack(arg);
    b = NULL;
    // if (!is_sorted(a))
	// 	start_sort(&a, &b, lst_len(a));
	// free_lst(a);
	return (0);

   
}