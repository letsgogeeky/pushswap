/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:09:12 by ramoussa          #+#    #+#             */
/*   Updated: 2023/10/01 19:56:21 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

static int	execute_operation(t_program *env, char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(env);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(env);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(env, env->should_log);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(env, env->should_log);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(env, env->should_log);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(env, env->should_log);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(env, env->should_log);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(env, env->should_log);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(env, env->should_log);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(env, env->should_log);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(env, env->should_log);
	else
		return (-1);
	return (0);
}

static void	perform_operations(t_program *env)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return ;
		if (execute_operation(env, line) == -1)
			abort_exit(env, 1);
		free(line);
	}
}

void	init(t_program *env)
{
	env->a = NULL;
	env->b = NULL;
	env->should_log = 0;
	env->length = get_actual_count(env);
	env->meta = (int *)malloc(sizeof(int) * env->length);
	env->sorted_meta = (int *)malloc(sizeof(int) * env->length);
	if (!env->sorted_meta || !env->meta)
		abort_exit(env, 1);
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
	perform_operations(env);
	if (is_sorted(env->a) && !env->b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
