/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/10 04:25:43 by ramoussa         ###   ########.fr       */
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
int	find_pivot(int a, int b, int c)
{
	if (a > b && b > c)
		return (b);
	if (a > b && a < c)
		return (a);
	return (c);
}
int	insert_sorted(t_program *env)
{
	t_doubly_list	*head;
	int				ops;
	int				pivot;

	head = env->b;
	ops = 0;
	pivot = find_pivot(env->a->data, env->min_in_b, env->max_in_b);
	if (env->a->data >= pivot && env->b->data > pivot && env->a->data < env->b->data)
	{
		while (head != env->b->prev)
		{
			if (env->a->data > env->max_in_b && env->b->prev->data == env->max_in_b)
				break;
			if (env->a->data < env->min_in_b && env->b->data == env->min_in_b)
				break;
			if (env->a->data > env->b->prev->data && env->a->data < env->b->data)
				break;
			rrb(env, env->should_log);
			ops++;
		}
	}
	else {
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
	}
	pb(env);
	ops++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	// if (env->b->data > env->b->next->data)
	// 	sb(env);
	return (ops);
}
void	compute_min_max(t_doubly_list *stack, int *min, int *max)
{
	t_doubly_list	*current;

	current = stack;
	while (current && current->next != stack)
	{
		update_min_max(stack, min, max);
		current = current->next;
	}
	update_min_max(stack, min, max);
}
int	stack_iterator(t_program *env)
{
	int	operations;
	t_doubly_list	*head;

	operations = 0;
	head = env->a;
	// while(env->a)
	// {
	// 	if (env->a->data > env->pivot)
	// 		operations += insert_sorted(env);
	// 	if (env->a->next == head)
	// 		break;
	// 	ra(env, env->should_log);
	// }
	while (env->a)
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
	}
	// compute_min_max(env->a, &env->min_in_a, &env->max_in_a);
	while (env->b->data != env->min_in_b)
	{
		rb(env, env->should_log);
		operations++;
	}
	return (operations);
}

int	insertion_quick_sort(t_program *env)
{
	int				operations;

	operations = 0;
	env->pivot = env->min + ((env->max - env->min) / 2);
	pb(env);
	operations++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	pb(env);
	operations++;
	update_min_max(env->b, &env->min_in_b, &env->max_in_b);
	operations += stack_iterator(env);
	return (operations);
}

int	stack_len(t_doubly_list *stack)
{
	t_doubly_list	*current;
	int				len;

	current = stack;
	len = 0;
	while (current && current->next != stack)
	{
		len++;
		current = current->next;
	}
	len++;
	return (len);
}

int	find_min(t_doubly_list *stack)
{
	t_doubly_list	*current;
	int				min;

	current = stack;
	min = current->data;
	while (current && current->next != stack)
	{
		current = current->next;
		if (min > current->data)
			min = current->data;
	}
	return (min);
}

int	find_max(t_doubly_list *stack)
{
	t_doubly_list	*current;
	int				max;

	current = stack;
	max = current->data;
	while (current && current->next != stack)
	{
		current = current->next;
		if (max < current->data)
			max = current->data;
	}
	return (max);
}
int	find_cost_forward(t_program *env, t_doubly_list *stack, int item)
{
	int				moves;
	t_doubly_list	*current;

	current = stack;
	moves = 0;
	(void)env;
	while (current)
	{
		if (item > current->prev->data && item < current->data)
			break;
		moves++;
		current = current->next;
	}
	return (moves);
}

int	find_cost_backward(t_program *env, t_doubly_list *stack, int item)
{
	int				moves;
	t_doubly_list	*current;

	(void)env;
	current = stack;
	moves = 0;
	while (current)
	{
		if (item > current->prev->data && item < current->data)
			break;
		moves++;
		current = current->prev;
	}
	return (moves);
}
int	get_real_cost(int cost, int min, int min_back)
{
	if (cost + min < cost + min_back)
		return (cost + min);
	return (cost + min_back);
}

int	find_idx (t_doubly_list *stack, int data)
{
	t_doubly_list	*current;
	id_t			idx;

	idx = 0;
	current = stack;
	while (current->next != stack)
	{
		if (current->data == data)
			return (idx);
		idx++;
		current = current->next;
	}
	return (idx);
}
int	get_diff(int a, int b)
{
	int	d;

	d = a - b;
	if (d < 0)
		d *= -1;
	return (d);
}

int	bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	smaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_cost_case	lowest_cost(t_program *env)
{
	int				cost;
	int				cost_back;
	int				min_cost;
	int				item;
	t_doubly_list	*current;
	t_cost_case		result;
	int				idx;
	int				len;

	len = stack_len(env->b);
	idx = 0;
	current = env->b;
	while(idx < len)
	{
		cost = find_cost_forward(env, env->a, env->b->data);
		cost_back = find_cost_backward(env, env->a, env->b->data);
		if (bigger(cost, idx) < cost + (len - idx))
		{
			result.total_cost = bigger(cost, idx);
			result.move_case = HAS_RR;
			result.double_move_count = smaller(cost, idx);
			if (cost > idx)
				result.higher_cost_stack = 'a';
			else
				result.higher_cost_stack = 'b';
		}
		if (bigger(cost, idx) > cost + (len - idx))
		{
			result.total_cost = cost + (len - idx);
			result.move_case = ONLY_R;
		}
		if (bigger(cost_back, len - idx) < cost_back + idx && bigger(cost_back, len - idx) < result.total_cost)
		{
			result.total_cost = bigger(cost_back, len - idx);
			result.move_case = HAS_RRR;
			result.double_move_count = smaller(cost_back, len - idx);
			if (cost_back > len - idx)
				result.higher_cost_stack = 'a';
			else
				result.higher_cost_stack = 'b';
		}
		else
		{
			result.total_cost = cost_back + idx;
			result.move_case = ONLY_RR;
		}
		if (result.total_cost < min_cost)
		{
			min_cost = result.total_cost;
			item = current->data;
			result.data = item;
		}
		idx++;
		current = current->next;
	}
	return (result);
}

int greedy_iterator(t_program *env)
{
	// t_doubly_list	*head;
	// int				idx_b_back;
	// int				cost_a;
	// int				cost_a_back;
	t_cost_case		item;
	int				ops;
	int				iters;
	int				ops_estimated;
	int				len_b;
	// int				idx_in_b;
	
	ops = 0;
	iters = 0;
	ops_estimated = 0;
	len_b = stack_len(env->b);
	while (env->b)
	{
		ft_printf("New Iteration starting...\n");
		item = lowest_cost(env);
		if (item.move_case == HAS_RR)
		{
			ft_printf("HAS_RR\n");
			while (item.double_move_count > 0)
			{
				rr(env, env->should_log);
				item.double_move_count--;
				item.total_cost--;
				ops++;
			}
			while (item.total_cost > 0)
			{
				if (item.higher_cost_stack == 'a')
					ra(env, env->should_log);
				else
					rb(env, env->should_log);
				ops++;
				item.total_cost--;
			}
		}
		else if (item.move_case == HAS_RRR)
		{
			ft_printf("HAS_RRR\n");
			while (item.double_move_count > 0)
			{
				rrr(env, env->should_log);
				item.double_move_count--;
				item.total_cost--;
				ops++;
			}
			while (item.total_cost > 0)
			{
				if (item.higher_cost_stack == 'a')
					rra(env, env->should_log);
				else
					rrb(env, env->should_log);
				ops++;
				item.total_cost--;
			}
		}
		else if (item.move_case == ONLY_R)
		{
			ft_printf("ONLY_R\n");
			while (item.total_cost > 0)
			{
				ra(env, env->should_log);
				ops++;
				item.total_cost--;
			}
		}
		else
		{
			ft_printf("HAS_RR\n");
			while (item.total_cost > 0)
			{
				rra(env, env->should_log);
				ops++;
				item.total_cost--;
			}
		}
		// ft_printf("Estimated cost forward: %d | backward: %d\n", cost_a, cost_a_back);
		// if (cost_a < cost_a_back && cost_b < cost_b_back)
		// {
		// 	if (cost_a > cost_b)
		// 		iters = cost_b;
		// 	else
		// 		iters = cost_a;
		// 	while (iters > 0)
		// 	{
		// 		rr(env, env->should_log);
		// 		ops++;
		// 		iters--;
		// 	}
		// 	while (env->b->data != item)
		// 	{
		// 		rb(env, env->should_log);
		// 		iters++;
		// 		ops++;
		// 	}
		// }
		// else if (cost_a > cost_a_back && cost_b > cost_b_back)
		// {
		// 	if (cost_a > cost_b)
		// 		iters = cost_b;
		// 	else
		// 		iters = cost_a;
		// 	while (iters > 0)
		// 	{
		// 		rrr(env, env->should_log);
		// 		ops++;
		// 		iters--;
		// 	}
		// 	while (env->b->data != item)
		// 	{
		// 		rrb(env, env->should_log);
		// 		iters++;
		// 		ops++;
		// 	}
		// }
		// else
		// {
		ft_printf("Item on top of B: %d | Item to push: %d\n", env->b->data, item.data);
		// if (idx_in_b > idx_b_back)
		// {
		// 	while(env->b->data != item)
		// 	{
		// 		rrb(env, env->should_log);
		// 		ops++;
		// 	}
		// }
		// else
		// {
		// 	while(env->b->data != item)
		// 	{
		// 		rb(env, env->should_log);
		// 		ops++;
		// 	}
		// }
		// ft_printf("B Rotations Operations needed for %d is %d\n", item, ops - ops_estimated);
		// // }
		// if (cost_a < cost_a_back)
		// {
		// 	while (env->a)
		// 	{
		// 		if (env->b->data > env->a->prev->data && env->b->data < env->a->data)
		// 			break;
		// 		ra(env, env->should_log);
		// 		ops++;
		// 		cost_a--;
		// 	}
		// }
		// else
		// {
		// 	while (env->a)
		// 	{
		// 		if (env->b->data > env->a->prev->data && env->b->data < env->a->data)
		// 			break;
		// 		rra(env, env->should_log);
		// 		ops++;
		// 		cost_a_back--;
		// 	}
		// }
		pa(env);
		ops++;
		ft_printf("Operations needed for %d is %d\n", item.data, ops - ops_estimated);
		ops_estimated = ops;
		ft_printf("Stack A: ");
		print_stack(env->a, ' ');
		ft_printf("\nStack B: ");
		print_stack(env->b, ' ');
		ft_printf("\n");
		ft_printf("-----------------------------\n");
	}
	while (env->a->data != env->min)
	{
		ra(env, env->should_log);
		ops++;
	}
	return (ops);
}

int	greedy(t_program *env)
{
	t_doubly_list	*current;
	size_t				idx;
	int	operations;

	operations = 0;
	idx = 0;
	current = env->a;
	while (idx < env->length)
	{
		if (env->a->data != env->min && env->a->data != env->max)
			pb(env);
		else
			ra(env, env->should_log);
		idx++;
		operations++;
	}
	if (env->b->data > env->a->data)
	{
		ra(env, env->should_log);
		pa(env);
		operations++;
	}
	else
	{
		pa(env);
		operations++;
	}

	ft_printf("Stack A: ");
	print_stack(env->a, ' ');
	ft_printf("\nStack B: ");
	print_stack(env->b, ' ');
	ft_printf("\n");
	operations += greedy_iterator(env);
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
	env->should_log = 0;
	
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
	env->min = find_min(env->a);
	env->max = find_max(env->a);
	operations = greedy(env);
	print_stack(env->a, ' ');
	ft_printf("\n");
	print_stack(env->b, ' ');
	// operations += insertion_quick_sort(env);
	ft_printf("\nAfter sorting\n");
	print_stack(env->a, ' ');
	ft_printf("\nTotal Operations: %d\n", operations);
	if (is_sorted(env->a))
		ft_printf("Oh wow!! it's sorted!!\n");
	else
		ft_printf("Something got messed up man!!\n");
	return (0);
}
