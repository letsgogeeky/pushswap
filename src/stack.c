/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:05:25 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:33:36 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_doubly_list	*create_node(t_doubly_list *head, t_doubly_list *prev, int data)
{
	t_doubly_list	*node;

	node = (t_doubly_list *)malloc(sizeof(t_doubly_list));
	node->data = data;
	node->idx = 0;
	node->prev = prev;
	node->next = head;
	if (head)
		head->prev = node;
	else
	{
		node->next = node;
		node->prev = node;
	}
	return (node);
}

void	print_stack(t_doubly_list *stack, char separator)
{
	t_doubly_list	*current;

	current = stack;
	while (current)
	{
		ft_printf("idx: %d | data: %d%c", \
			current->idx, current->data, separator);
		current = current->next;
		if (current && current->data == stack->data)
			break ;
	}
}

int	is_duplicate(t_program *env, int num, int to_idx)
{
	int	idx;

	idx = 0;
	while (idx < to_idx)
	{
		if (env->meta[idx] == num)
			return (1);
		idx++;
	}
	return (0);
}

int	is_sorted(t_doubly_list *stack)
{
	t_doubly_list	*current;

	current = stack;
	while (1)
	{
		if (current->next->data == stack->data)
			break ;
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
