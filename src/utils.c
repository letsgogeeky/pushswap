/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:44:33 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:32:13 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	approx_sqrt(int num)
{
	int	i;

	i = 1;
	while (i * i <= num)
		i++;
	return (i - 1);
}

int	max_index_in_list(t_doubly_list *stack)
{
	t_doubly_list	*current;
	int				biggest;

	biggest = INT_MIN;
	current = stack;
	while (current)
	{
		if (current->idx > biggest)
			biggest = current->idx;
		current = current->next;
		if (current && current == stack)
			break ;
	}
	return (biggest);
}

int	min_index_in_list(t_doubly_list *stack)
{
	t_doubly_list	*current;
	int				min;

	min = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->idx < min)
			min = current->idx;
		current = current->next;
		if (current && current == stack)
			break ;
	}
	return (min);
}

int	moves_to_idx(t_doubly_list *stack, int idx)
{
	int				moves;
	t_doubly_list	*current;

	current = stack;
	moves = 0;
	while (current)
	{
		if (current->idx == idx)
			return (moves);
		moves++;
		current = current->next;
	}
	return (moves);
}
