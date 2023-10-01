/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:54 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 01:44:34 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/ft-baselib/include/baselib.h"

typedef struct s_doubly_list
{
	int						data;
	int						idx;
	struct s_doubly_list	*next;
	struct s_doubly_list	*prev;
}	t_doubly_list;

typedef struct s_program
{
	char			**argv;
	int				length;
	int				partitions_count;
	int				*meta;
	int				*sorted_meta;
	t_doubly_list	*a;
	t_doubly_list	*b;
	int				should_log;
}	t_program;

t_doubly_list	*create_node( \
			t_doubly_list *head, \
			t_doubly_list *prev, \
			int data);
void			print_stack(t_doubly_list *stack, char separator);
int				is_duplicate(t_program *env, int num, int to_idx);
int				is_sorted(t_doubly_list *stack);

int				get_actual_count(t_program *env);
int				parse(t_program *env);
void			build_stacks(t_program *env);

void			sa(t_program *env, int should_log);
void			sb(t_program *env, int should_log);
void			ss(t_program *env, int should_log);
void			ra(t_program *env, int should_log);
void			rb(t_program *env, int should_log);
void			rr(t_program *env, int should_log);
void			rra(t_program *env, int should_log);
void			rrb(t_program *env, int should_log);
void			rrr(t_program *env, int should_log);
void			pa(t_program *env);
void			pb(t_program *env);

void			sort_meta(t_program *env);
int				get_index_from_meta(t_program *env, int data);

int				approx_sqrt(int num);
int				max_index_in_list(t_doubly_list *stack);
int				min_index_in_list(t_doubly_list *stack);
int				moves_to_idx(t_doubly_list *stack, int idx);

void			partition_stack(t_program *env);
void			sort_partitions(t_program *env);
void			sort_factory(t_program *env);

void			abort_exit(t_program *env);
#endif
