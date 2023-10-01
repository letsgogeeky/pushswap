/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_big.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:49:52 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:41:14 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	partition_stack(t_program *env)
{
	int	idx;
	int	partition_size;

	idx = 0;
	partition_size = env->length / env->partitions_count;
	while (env->a)
	{
		if (env->a->idx <= idx)
		{
			pb(env);
			rb(env, env->should_log);
			idx++;
		}
		else if (env->a->idx <= idx + partition_size)
		{
			pb(env);
			idx++;
		}
		else
			ra(env, env->should_log);
	}
}

void	sort_partitions(t_program *env)
{
	int	size;
	int	count_r;
	int	count_rr;

	size = env->length;
	while (size > 0)
	{
		count_r = moves_to_idx(env->b, size - 1);
		count_rr = size - count_r;
		if (count_r <= count_rr)
		{
			while (env->b->idx != size - 1)
				rb(env, env->should_log);
			pa(env);
		}
		else
		{
			while (env->b->idx != size - 1)
				rrb(env, env->should_log);
			pa(env);
		}
		size--;
	}
}
