/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:42 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/02 18:52:52 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	ra(t_program *env)
{
	if (env->a && env->a->next)
		env->a = env->a->next;
	ft_printf("ra\n");
}

void	rb(t_program *env)
{
	if (env->b && env->b->next)
		env->b = env->b->next;
	ft_printf("rb\n");
}

void	rr(t_program *env)
{
	ra(env);
	rb(env);
}
