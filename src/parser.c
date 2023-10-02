/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:46:10 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 22:51:14 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	get_actual_count(t_program *env)
{
	int		count;
	int		idx;
	char	**parts;

	count = 0;
	idx = 1;
	while (env->argv[idx])
	{
		parts = ft_split(env->argv[idx], ' ');
		if (!parts)
			abort_exit(env, 1);
		count += str_arr_len(parts);
		idx++;
		str_arr_free(parts);
		parts = NULL;
	}
	return (count);
}

int	get_valid_int(t_program *env, char *str, int to_idx, char **parts)
{
	long long		current;

	current = ra_parse_long(str);
	if (!ra_is_int(str) || !ra_int_in_bound(current) \
			|| is_duplicate(env, current, to_idx))
	{
		str_arr_free(parts);
		free(env->meta);
		free(env->sorted_meta);
		abort_exit(env, 1);
	}
	return (current);
}

static char	**ft_split_guarded(t_program *env, char *str)
{
	char	**parts;

	parts = ft_split(str, ' ');
	if (!parts)
	{
		free(env->meta);
		free(env->sorted_meta);
		abort_exit(env, 1);
	}
	return (parts);
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
		parts = ft_split_guarded(env, env->argv[idx]);
		parts_idx = 0;
		while (parts[parts_idx])
		{
			current = get_valid_int(env, parts[parts_idx], lst_idx, parts);
			env->meta[lst_idx] = current;
			env->sorted_meta[lst_idx] = current;
			lst_idx++;
			parts_idx++;
		}
		str_arr_free(parts);
		idx++;
	}
	return (0);
}
