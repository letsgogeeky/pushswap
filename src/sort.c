/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:42:56 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/30 03:05:22 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_small(t_program *env)
{
	t_doubly_list	*current;
	int				biggest;

	current = env->a;
	biggest = max_index_in_list(env->a);
	if (!is_sorted(env->a))
	{
		if (current->idx == biggest)
			ra(env, env->should_log);
		else if (current->next->idx == biggest)
			rra(env, env->should_log);
		current = env->a;
		if (current->idx > current->next->idx)
			sa(env, env->should_log);
	}
}

void	sort_lt_seven(t_program *env)
{
	int	idx;
	int	moves;
	int	min_idx;

	idx = 0;
	while (idx < env->length - 3)
	{
		min_idx = min_index_in_list(env->a);
		moves = moves_to_idx(env->a, min_idx);
		if (moves < env->length - moves)
			while (env->a->idx != min_idx)
				ra(env, env->should_log);
		else
			while (env->a->idx != min_idx)
				rra(env, env->should_log);
		pb(env);
		idx++;
	}
	sort_small(env);
	while (env->b)
		pa(env);
}

void	go_big(t_program *env)
{
	partition_stack(env);
	sort_partitions(env);
}

void	sort_factory(t_program *env)
{
	if (env->length == 2)
		ra(env, env->should_log);
	if (env->length <= 3)
		sort_small(env);
	else if (env->length <= 7)
		sort_lt_seven(env);
	else
		go_big(env);
}