/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:42 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/07 02:39:33 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	ra(t_program *env, int should_log)
{
	if (env->a && env->a->next)
		env->a = env->a->next;
	if (should_log)
		ft_printf("ra\n");
}

void	rb(t_program *env, int should_log)
{
	if (env->b && env->b->next)
		env->b = env->b->next;
	if (should_log)
		ft_printf("rb\n");
}

void	rr(t_program *env, int should_log)
{
	ra(env, 0);
	rb(env, 0);
	if (should_log)
		ft_printf("rr\n");
}
