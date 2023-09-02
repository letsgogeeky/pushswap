/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/02 19:44:11 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
a = 1 - 9 - 6 - 8 - 2
iter 0: pb ->	a = 9 - 6 - 8 - 2		|| b = 1 			max = 1, min = 1;
iter 1: pb ->	a = 6 - 8 - 2 			|| b = 9 - 1		max = 9, min = 1;
iter 2: pb ->	a = 8 - 2				|| b = 6 - 9 - 1	max = 9, min = 1;
iter 3: rrb ->	a = 8 - 2				|| b = 9 - 1 - 6
iter 3: pb ->	a = 2					|| b = 8 - 9 - 1 - 6
iter 4: rrb ->	a = 2					|| b = 9 - 1 - 6 - 8
iter 4: rrb -> 	a = 2					|| b = 1 - 6 - 8 - 9
iter 4: rrb -> 	a = 2					|| b = 6 - 8 - 9 - 1
iter 4: pb ->	a = NULL				|| b = 2 - 6 - 8 - 9 - 1
*/
void	insert_sorted(t_program *env)
{
	if (!env->b || env->b->data == env->b->next->data)
	{
		pb(env);
		if (env->b->data > env->max_in_b)
			env->max_in_b = env->b->data;
		if (env->b->data < env->min_in_b)
			env->min_in_b = env->b->data;
		return ;
	}
	if (env->a->data < env->b->data)
	{
		while (env->a->data < env->b->data)
			rrb(env);
	}
	else
	{
		while (env->a->data > env->b->data && env->b->data < env->b->next->data)
			rb(env);
		if (env->a->data > env->max_in_b)
			rb(env);
	}
	if (env->b->data > env->max_in_b)
		env->max_in_b = env->b->data;
	if (env->b->data < env->min_in_b)
		env->min_in_b = env->b->data;
	pb(env);
}

void	stack_iterator(t_program *env)
{
	while(env->a)
	{
		// if (env->a->data > env->a->prev->data && env->a->data > env->a->next->data)
		insert_sorted(env);
		// else if (env->a->data < env->a->)
	}
}

int	main(int argc, char **argv)
{
	int	idx;
	t_program	*env;
	long long	current;
	t_doubly_list		*a_cursor;

	if (argc < 2)
		return (1);
	idx = 1;
	env = (t_program *)malloc(sizeof(t_program));
	env->length = 0;
	env->min_in_b = INT_MAX;
	env->max_in_b = INT_MIN;
	while (argv[idx])
	{
		env->length++;
		idx++;
	}
	idx = 1;
	current = ra_parse_long(argv[idx]);
	if (!ra_is_int(argv[idx]) || !ra_int_in_bound(current))
	{
		ft_printf("Error\n");
		return (1);
	}
	env->a = create_node(NULL, NULL, current);
	a_cursor = env->a;
	idx++;
	while(argv[idx])
	{
		if (!ra_is_int(argv[idx]))
		{
			ft_printf("ERROR: NAN..!\n");
			return (1);
		}
		current = ra_parse_long(argv[idx]);
		if (!ra_int_in_bound(current))
		{
			ft_printf("ERROR: Num outside Integer bounds...!\n");
			return (1);
		}
		if (is_duplicate(env->a, current))
		{
			ft_printf("Error: Duplicate!!\n");
			return (1);
		}
		a_cursor->next = create_node(env->a, a_cursor, current);
		a_cursor = a_cursor->next;
		idx++;
	}
	// sa(env);
	// ra(env);
	// ft_printf("Printing A\n");
	// print_stack(env->a);
	// ft_printf("Printing B\n");
	// pb(env);
	// pb(env);
	// print_stack(env->b);
	// ft_printf("Printing A\n");
	// print_stack(env->a);
	// ft_printf("Printing A Before sorting\n");
	// print_stack(env->a);
	stack_iterator(env);
	ft_printf("After sorting\n");
	print_stack(env->b);
	return (0);
}
