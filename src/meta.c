/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:18:36 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:36:46 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_meta(t_program *env)
{
	int	idx;
	int	forward;
	int	tmp;

	idx = 0;
	while (idx < env->length - 1)
	{
		forward = 0;
		while (forward < env->length - idx - 1)
		{
			if (env->sorted_meta[forward] > env->sorted_meta[forward + 1])
			{
				tmp = env->sorted_meta[forward];
				env->sorted_meta[forward] = env->sorted_meta[forward + 1];
				env->sorted_meta[forward + 1] = tmp;
			}
			forward++;
		}
		idx++;
	}
}

int	get_index_from_meta(t_program *env, int data)
{
	int	idx;

	idx = 0;
	while (idx < env->length)
	{
		if (env->sorted_meta[idx] == data)
			return (idx);
		idx++;
	}
	return (-1);
}
