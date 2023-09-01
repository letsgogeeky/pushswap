/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:38 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 03:36:01 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	rra(t_program *env)
{
	if (env->a && env->a->prev)
		env->a = env->a->prev;
}

void	rrb(t_program *env)
{
	if (env->b && env->b->prev)
		env->b = env->b->prev;
}

void	rrr(t_program *env)
{
	rra(env);
	rrb(env);
}
