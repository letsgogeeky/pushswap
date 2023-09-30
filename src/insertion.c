/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:04:59 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/30 22:51:41 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	build_stacks(t_program *env)
{
	int	idx;
	t_doubly_list	*a_cursor;

	idx = 0;
	parse(env);
	sort_meta(env);
	while(idx < env->length)
	{
		if (idx == 0)
		{
			env->a = create_node(0, 0, env->meta[idx]);
			a_cursor = env->a;
		}
		else
		{
			a_cursor->next = create_node(env->a, a_cursor, env->meta[idx]);
			a_cursor = a_cursor->next;	
		}
		a_cursor->idx = get_index_from_meta(env, a_cursor->data);
		idx++;
	}
}
