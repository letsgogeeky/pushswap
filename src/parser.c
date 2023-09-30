/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:46:10 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 00:36:04 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	abort_exit(t_program *env)
{
	ft_putstr_fd("Error\n", 2);
	free(env->meta);
	free(env->sorted_meta);
	exit(1);
}

int	get_actual_count(t_program *env)
{
	int		count;
	int		idx;

	count = 0;
	idx = 1;
	while (env->argv[idx])
	{
		count += str_arr_len(ft_split(env->argv[idx], ' '));
		idx++;
	}
	return (count);
}

int	get_valid_int(t_program *env, char *str, int to_idx)
{
	long long		current;

	current = ra_parse_long(str);
	if (!ra_is_int(str) || !ra_int_in_bound(current))
		abort_exit(env);
	if (is_duplicate(env, current, to_idx))
		abort_exit(env);
	return (current);
}

int	parse(t_program *env)
{
	int			idx;
	long long	current;
	char		**parts;
	int			parts_idx;
	int			lst_idx;

	lst_idx = 0;
	idx = 1;
	while (env->argv[idx])
	{
		parts = ft_split(env->argv[idx], ' ');
		parts_idx = 0;
		while (parts[parts_idx])
		{
			current = get_valid_int(env, parts[parts_idx], lst_idx);
			env->meta[lst_idx] = current;
			env->sorted_meta[lst_idx] = current;
			lst_idx++;
			parts_idx++;
		}
		idx++;
	}
	return (0);
}
