/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:54 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 00:49:03 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/ft-baselib/include/baselib.h"

typedef struct s_stack
{
	int	data;
	struct	s_stack *next;
}	t_stack;

typedef struct s_program
{
	char		**argv;
	int			argc;
	size_t		length;
	t_stack		*a;
	t_stack		*b;
	size_t		a_len;
	size_t		b_len;
}	t_program;

t_stack	*create_node(int data);
void	print_stack(t_stack *stack);
int		is_duplicate(t_stack *stack, int num);

#endif
