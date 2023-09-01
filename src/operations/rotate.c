/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:42 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 01:31:55 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	ra(t_program *env)
{
	if (env->a && env->a->next)
		env->a = env->a->next;
}

void	rb(t_program *env)
{
	if (env->b && env->b->next)
		env->b = env->b->next;
}

void	rr(t_program *env)
{
	ra(env);
	rb(env);
}
