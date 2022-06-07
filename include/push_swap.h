/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 16:36:37 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/07 17:52:57 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
#include <stdio.h>
#include <ctype.h> 
#include <stddef.h>

typedef struct node
{
	int			i;
	struct node	*previous;
	struct node	*next;
}   t_stack;

//main.c
void	free_message_exit(char **mat);
void	free_arr(char **arg);
void 	free_list(t_stack *node);
void	printlist(t_stack *a);

//parser
char	**fill_array(int argc, char **argv);
char	**get_inp(int argc, char **argv);

//inputcheck
int     ft_error(char **arg);
int	    ft_isnumber(char *arg);
int	    ft_dupl(char **arg);
int	    ft_isint(char *arg);
int     check_sorted(t_stack **stack);

//list.c
void	listadd_back(t_stack **stack, t_stack *current);
int		list_len(t_stack *stack);
t_stack	*list_last(t_stack *stack);
t_stack	*list_new(int num);

//sort.c
void    sort(t_stack **a, t_stack **b);
void    indexsort(t_stack **a, t_stack **b);
void    two_numbers(t_stack **a);
void    three_numbers(t_stack **a, int min, int max);
void	four(t_stack **a, int min, int max);
void	five(t_stack **a, int min);
int     maxnumber(t_stack *a);
int     minnumber(t_stack *k);
int		secondminnumber(t_stack *k);
void	radix(t_stack **a, t_stack **b);
void	index_numbers(t_stack **radix, t_stack *origin);
void	sort_many(t_stack **a, t_stack **b);
int		is_lownb_sorted(t_stack *stack);

//commands.c
void	pushstack(t_stack **dest, t_stack **src, char stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap(t_stack **stack, char stackchar);
#endif
