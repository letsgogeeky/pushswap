/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:35 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/09 23:57:57 by ramoussa         ###   ########.fr       */
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
	if (tmp->data != head->data)
	{
		tmp->prev = head->prev;
		head->prev->next = tmp;
		env->b = tmp;
	}
	else
		env->b = NULL;
	tmp = env->a;
	if (!tmp)
	{
		env->a = head;
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->next = tmp;
		head->prev = tmp->prev;
		tmp->prev->next = head;
		tmp->prev = head;
		env->a = head;
	}
	if (env->should_log)
		ft_printf("pa\n");
}

void	pb(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;
	
	if (!env->a)
		return ;
	head = env->a;
	tmp = head->next;
	if (tmp->data != head->data)
	{
		tmp->prev = head->prev;
		head->prev->next = tmp;
		env->a = tmp;
	}
	else
		env->a = NULL;
	tmp = env->b;
	if (!tmp)
	{
		env->b = head;
		head->next = head;
		head->prev = head;
	}
	else
	{
		head->next = tmp;
		head->prev = tmp->prev;
		tmp->prev->next = head;
		tmp->prev = head;
		env->b = head;
	}
	if (env->should_log)
		ft_printf("pb\n");
}
