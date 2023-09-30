/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/09/30 22:52:55 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_program		*env;

	if (argc < 2)
		return (1);
	env = (t_program *)malloc(sizeof(t_program));
	env->should_log = 1;
	env->argv = argv;
	env->length = get_actual_count(env);
	env->meta = (int *)malloc(sizeof(int) * env->length + 1);
	env->sorted_meta = (int *)malloc(sizeof(int) * env->length + 1);
	if (ft_strlen(argv[1]) == 0)
		abort_exit(env);
	env->partitions_count = 20;
	if (env->length < 150)
		env->partitions_count = 7;
	build_stacks(env);
	if (is_sorted(env->a))
		return (0);
	sort_factory(env);
	return (0);
}
