/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:54 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 19:30:30 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/ft-baselib/include/baselib.h"

typedef struct s_doubly_list
{
	int	data;
	struct	s_doubly_list	*next;
	struct	s_doubly_list	*prev;
}	t_doubly_list;

typedef struct s_program
{
	char		**argv;
	int			argc;
	size_t		length;
	t_doubly_list		*a;
	t_doubly_list		*b;
	size_t		a_len;
	size_t		b_len;
}	t_program;

t_doubly_list	*create_node(t_doubly_list *head, t_doubly_list *prev, int data);
void			print_stack(t_doubly_list *stack);
int				is_duplicate(t_doubly_list *stack, int num);

void			sa(t_program *env);

void			ra(t_program *env);
void			pa(t_program *env);
void			pb(t_program *env);

#endif
