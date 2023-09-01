/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:35 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 19:29:57 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;
	
	if (!env->b)
		return ;
	head = env->b;
	tmp = head->next;
	if (tmp)
		tmp->prev = head->prev;
	if (head->prev)
		head->prev->next = tmp;
	env->b = tmp;
	tmp = env->a;
	if (!tmp)
	{
		env->a = head;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		head->next = tmp;
		head->prev = tmp->prev;
		tmp->prev->next = head;
		tmp->prev = head;
		env->a = head;
	}
}

void	pb(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;
	
	if (!env->a)
		return ;
	head = env->a;
	tmp = head->next;
	if (tmp)
		tmp->prev = head->prev;
	if (head->prev)
		head->prev->next = tmp;
	env->a = tmp;
	tmp = env->b;
	if (!tmp)
	{
		env->b = head;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		head->next = tmp;
		head->prev = tmp->prev;
		tmp->prev->next = head;
		tmp->prev = head;
		env->b = head;
	}
}
