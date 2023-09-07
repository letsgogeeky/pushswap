/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/07 03:36:17 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		rb(env, env->should_log);
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
		if (env->a->data < env->a->next->data && env->a->data < env->a->prev->data)
			operations += insert_sorted(env);
		else if (env->a->data > env->a->next->data && env->a->prev->data > env->a->next->data)
		{
			if (env->a->next->data > env->b->data)
				rr(env, env->should_log);
			else
				ra(env, env->should_log);
			operations++;
			operations += insert_sorted(env);
		}
		else if (env->a->data > env->a->prev->data && env->a->next->data > env->a->prev->data)
		{
			if (env->a->prev->data < env->b->prev->data)
				rrr(env, env->should_log);
			else
				rra(env, env->should_log);
			operations++;
			operations += insert_sorted(env);
		}
		else 
		{
			operations += insert_sorted(env);
		}
		// operations += insert_sorted(env);
		print_stack(env->b, ' ');
		// else if (env->a->data < env->a->)
	}
	while (env->b->data != env->min_in_b)
	{
		rb(env, env->should_log);
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
	env->should_log = 1;
	env->min = INT_MAX;
	env->max = INT_MIN;
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
		if (current > env->max)
			env->max = current;
		if (current < env->min)
			env->min = current;
		idx++;
	}
	if (is_sorted(env->a))
	{
		ft_printf("List already sorted!\n");
		return (0);
	}
	env->pivot = env->min + ((env->max - env->min) / 2);
	pb(env);
	operations++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	pb(env);
	operations++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	operations += stack_iterator(env);
	ft_printf("After sorting\n");
	print_stack(env->b, ' ');
	ft_printf("\nTotal Operations: %d\n", operations);
	if (is_sorted(env->b))
		ft_printf("Oh wow!! it's sorted!!\n");
	return (0);
}
