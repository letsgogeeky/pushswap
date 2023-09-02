/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:38 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/02 18:52:15 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	rra(t_program *env)
{
	if (env->a && env->a->prev)
		env->a = env->a->prev;
	ft_printf("rra\n");
}

void	rrb(t_program *env)
{
	if (env->b && env->b->prev)
		env->b = env->b->prev;
	ft_printf("rrb\n");
}

void	rrr(t_program *env)
{
	rra(env);
	rrb(env);
}
