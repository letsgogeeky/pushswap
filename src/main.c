/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/06 01:55:25 by ramoussa         ###   ########.fr       */
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
void	update_min_max(t_doubly_list *stack, int *min, int *max)
{
	if (stack->data > *max)
		*max = stack->data;
	if (stack->data < *min)
		*min = stack->data;
}

int	insert_sorted(t_program *env)
{
	t_doubly_list	*head;
	int				ops;

	head = env->b;
	ops = 0;
	while (head != env->b->next)
	{
		if (env->a->data > env->max_in_b && env->b->prev->data == env->max_in_b)
			break;
		if (env->a->data < env->min_in_b && env->b->data == env->min_in_b)
			break;
		if (env->a->data > env->b->prev->data && env->a->data < env->b->data)
			break;
		rb(env);
		ops++;
	}
	pb(env);
	ops++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	// if (env->b->data > env->b->next->data)
	// 	sb(env);
	return (ops);
}

int	stack_iterator(t_program *env)
{
	int	operations;

	operations = 0;
	while(env->a)
	{
		// if (env->a->data > env->a->prev->data && env->a->data > env->a->next->data)
		operations += insert_sorted(env);
		print_stack(env->b, ' ');
		// else if (env->a->data < env->a->)
	}
	while (env->b->data != env->min_in_b)
	{
		rb(env);
		operations++;
	}
	return (operations);
}

int	main(int argc, char **argv)
{
	int				idx;
	t_program		*env;
	long long		current;
	t_doubly_list	*a_cursor;
	int				operations;

	if (argc < 2)
		return (1);
	idx = 1;
	operations = 0;
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
	if (is_sorted(env->a))
	{
		ft_printf("List already sorted!\n");
		return (0);
	}
	pb(env);
	operations++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	ft_printf("Min: %d, Max: %d\n", env->min_in_b, env->max_in_b);
	pb(env);
	operations++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	ft_printf("Min: %d, Max: %d\n", env->min_in_b, env->max_in_b);
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
	operations += stack_iterator(env);
	ft_printf("After sorting\n");
	print_stack(env->b, ' ');
	ft_printf("\nTotal Operations: %d\n", operations);
	if (is_sorted(env->b))
		ft_printf("Oh wow!! it's sorted!!\n");
	return (0);
}
