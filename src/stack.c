/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:05:25 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 00:48:45 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stack*	create_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->data = data;
	return (node);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while(current)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
}

int	is_duplicate(t_stack *stack, int num)
{
	t_stack	*current;

	current = stack;
	while(current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}