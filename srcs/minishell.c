/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 07:41:22 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/05 06:42:21 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int				main(int argc, char **argv, char **env)
{
	t_data	*data;

	(void)(argc && argv);
	data = init_env();
	enable_rawmode();
	config_termcaps(data);
	read_env(data, env);
	enable_signal(data);
	logo_set(data);
	while (1)
	{
		init_history(data);
		keypress(data);
		save_history(data);
		lexi(data);
		parse(data);
		run_first(data);
		free_first(data);
	}
	return (0);
}
