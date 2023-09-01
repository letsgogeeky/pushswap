/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:09:35 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 03:55:01 by ramoussa         ###   ########.fr       */
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
	// TODO: continue..
}