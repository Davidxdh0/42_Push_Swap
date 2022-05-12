/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 11:41:21 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/05/12 12:51:51 by dyeboa        ########   odam.nl         */
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

void	free_message_exit(char **arg)
{
	free_arr(arg);
	write(1, "Free_exit\n", 11);
	exit(0);
}

void free_list(t_stack *node) 
{
	t_stack	*temp;
	
  	while (node != NULL) 
  	{
    	temp = node->next;
    	free(node);
    	node = temp;
	} 
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
		//printf("%d", k);
		temp = list_new(k);
		if (!temp)
			break ;
		listadd_back(&a, temp);
		i++;
	}
	free_arr(arg);
	return (a);
}

void	printlist(t_stack *a)
{
	while (a)
	{
		printf("%d ", a->i);
		a = a->next;
	}
}

int main(int argc, char **argv)
{   
    char    **arg;
    t_stack *a;
    t_stack *b;
	
	if (argc == 1)
		exit(0);
    arg = get_inp(argc, argv);
    if (ft_error(arg) == 1 || !arg)
		free_message_exit(arg);
    else
        write(1, "werkt\n", 6);
    a = a_stack(arg);
	b = NULL;
	printf("list len = %d\n", list_len(a));
	// printlist(b);
	// if (!check_sorted(a))
	// {
		// printlist(a);
		//indexsort(a, b, list_len(a));
	// }
	printf("maxnumber = %d\n", maxnumber(a));

	if (!check_sorted(a))
	{
	 	printlist(a);
	 	sort(a, b, list_len(a));
		printlist(a);
	}
	// printlist(b);
	//sort(a, b,len list a)
	//??
	free_list(a); // list freeen
	return (0);
}