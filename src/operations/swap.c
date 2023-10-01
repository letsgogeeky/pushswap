/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:44 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:30:37 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	sa(t_program *env, int should_log)
{
	t_doubly_list	*first;
	t_doubly_list	*second;
	t_doubly_list	*tmp;

	first = env->a;
	if (!first || !first->next)
		return ;
	second = first->next;
	tmp = first->prev;
	first->prev = second;
	second->prev = tmp;
	first->next = second->next;
	second->next = first;
	env->a = second;
	first->next->prev = first;
	second->prev->next = second;
	if (should_log)
		ft_printf("sa\n");
}

void	sb(t_program *env, int should_log)
{
	t_doubly_list	*first;
	t_doubly_list	*second;
	t_doubly_list	*tmp;

	first = env->b;
	if (!first || !first->next)
		return ;
	second = first->next;
	tmp = first->prev;
	first->prev = second;
	second->prev = tmp;
	first->next = second->next;
	second->next = first;
	env->b = second;
	first->next->prev = first;
	second->prev->next = second;
	if (should_log)
		ft_printf("sb\n");
}

void	ss(t_program *env, int should_log)
{
	sa(env, 0);
	sb(env, 0);
	if (should_log)
		ft_printf("ss\n");
}
