/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:35 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:31:20 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_doubly_list	*set_new_head_b(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;

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
	return (head);
}

static t_doubly_list	*set_new_head_a(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;

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
	return (head);
}

void	pa(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;

	if (!env->b)
		return ;
	head = set_new_head_b(env);
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
	ft_printf("pa\n");
}

void	pb(t_program *env)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;

	if (!env->a)
		return ;
	head = set_new_head_a(env);
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
	ft_printf("pb\n");
}
