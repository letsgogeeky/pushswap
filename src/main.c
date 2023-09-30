/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/30 02:05:40 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	env->should_log = 1;
	env->length = argc - 1;
	env->meta = (int *)malloc(sizeof(int) * env->length + 1);
	env->sorted_meta = (int *)malloc(sizeof(int) * env->length + 1);
	env->partitions_count = 11;
	if (env->length < 150)
		env->partitions_count = 7;
	idx = 1;
	current = ra_parse_long(argv[idx]);
	if (!ra_is_int(argv[idx]) || !ra_int_in_bound(current))
	{
		ft_printf("Error\n");
		return (1);
	}
	env->a = create_node(NULL, NULL, current);
	env->meta[idx-1] = current;
	env->sorted_meta[idx-1] = current;
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
		env->meta[idx-1] = current;
		env->sorted_meta[idx-1] = current;
		idx++;
	}
	env->meta[idx - 1] = 0;
	env->sorted_meta[idx - 1] = 0;
	sort_meta(env);
	env->a->idx = get_index_from_meta(env, env->a->data);
	idx = 1;
	while(idx < env->length)
	{
		a_cursor->next = create_node(env->a, a_cursor, env->meta[idx]);
		a_cursor = a_cursor->next;
		a_cursor->idx = get_index_from_meta(env, a_cursor->data);
		idx++;
	}
	
	if (is_sorted(env->a))
		return (0);
	if (env->length == 2)
		ra(env, env->should_log);
	if (env->length <= 3)
		sort_small(env);
	else if (env->length <= 7)
		sort_lt_seven(env);
	else
		go_big(env);
	return (0);
}
