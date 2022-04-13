/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 16:36:37 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/04/13 15:11:17 by dyeboa        ########   odam.nl         */
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
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h> 
#include <stddef.h>

typedef struct s_stack
{
	int				i;
	struct s_stack	*previous;
	struct s_stack	*next;
}   t_stack;

//Pushswap
int     ft_error(char **arg);
int	    ft_isnumber(char *arg);
int	    ft_dupl(char **arg);
int	    ft_isint(char *arg);
char	**fill_array(int argc, char **argv);
char	**get_inp(int argc, char **argv);
int     ft_error(char **arg);
void	free_exit(char **mat);
void	free_mat(char **matrix);

#endif
