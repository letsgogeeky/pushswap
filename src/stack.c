/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:05:25 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 23:45:21 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_doubly_list*	create_node(t_doubly_list *head, t_doubly_list *prev, int data)
{
	t_doubly_list	*node;

	node = (t_doubly_list *)malloc(sizeof(t_doubly_list));
	node->data = data;
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

void	print_stack(t_doubly_list *stack)
{
	t_doubly_list	*current;

	current = stack;
	while(current)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
		if (current && current->data == stack->data)
			break;
	}
}

int	is_duplicate(t_doubly_list *stack, int num)
{
	t_doubly_list	*current;

	current = stack;
	while(current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
		if (current && current->data == stack->data)
			break;
	}
	return (0);
}