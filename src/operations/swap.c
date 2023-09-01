/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:44 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 03:47:47 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	sa(t_program *env)
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
}

void	sb(t_program *env)
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
}

void	ss(t_program *env)
{
	sa(env);
	sb(env);
}
