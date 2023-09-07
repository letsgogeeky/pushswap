/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:38 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/07 02:37:35 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	rra(t_program *env, int should_log)
{
	if (env->a && env->a->prev)
		env->a = env->a->prev;
	if (should_log)
		ft_printf("rra\n");
}

void	rrb(t_program *env, int should_log)
{
	if (env->b && env->b->prev)
		env->b = env->b->prev;
	if (should_log)
		ft_printf("rrb\n");
}

void	rrr(t_program *env, int should_log)
{
	rra(env, 0);
	rrb(env, 0);
	if (should_log)
		ft_printf("rrr\n");
}
