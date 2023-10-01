/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:47:50 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 19:55:25 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	init(t_program *env)
{
	env->a = NULL;
	env->b = NULL;
	env->should_log = 1;
	env->length = get_actual_count(env);
	env->meta = (int *)malloc(sizeof(int) * env->length);
	env->sorted_meta = (int *)malloc(sizeof(int) * env->length);
	if (!env->sorted_meta || !env->meta)
		abort_exit(env, 1);
	env->partitions_count = 20;
	if (env->length < 150)
		env->partitions_count = 7;
}

int	main(int argc, char **argv)
{
	t_program		*env;

	if (argc < 2)
		return (1);
	env = (t_program *)malloc(sizeof(t_program));
	if (env == NULL)
		exit(1);
	env->argv = argv;
	init(env);
	if (ft_strlen(argv[1]) == 0)
		abort_exit(env, 1);
	build_stacks(env);
	free(env->meta);
	free(env->sorted_meta);
	if (!is_sorted(env->a))
		sort_factory(env);
	abort_exit(env, 0);
	return (0);
}
