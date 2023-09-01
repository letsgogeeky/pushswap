/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/01 03:32:13 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	sa(env);
	ra(env);
	print_stack(env->a);
	return (0);
}
