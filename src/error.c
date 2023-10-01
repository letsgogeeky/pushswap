/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:59:48 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 19:40:14 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	free_list(t_doubly_list *lst)
{
	t_doubly_list	*head;
	t_doubly_list	*tmp;

	while (lst)
	{
		head = lst;
		tmp = head->next;
		if (tmp->data != head->data)
		{
			tmp->prev = head->prev;
			head->prev->next = tmp;
			lst = tmp;
		}
		else
			lst = NULL;
		free(head);
		head = NULL;
	}
}

void	abort_exit(t_program *env, int status)
{
	if (status > 0)
		ft_putstr_fd("Error\n", 2);
	if (env->a)
		free_list(env->a);
	if (env->b)
		free_list(env->b);
	free(env);
	exit(status);
}
