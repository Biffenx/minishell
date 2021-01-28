/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:41:10 by jwilen            #+#    #+#             */
/*   Updated: 2020/11/03 08:37:37 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	b_echo(char **s_args)
{
	size_t		i;

	i = 1;
	while (s_args[i])
	{
		ft_putstr(s_args[i]);
		if (s_args[i + 1])
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	builtins(t_data *data)
{
	if (ft_strcmp(data->s_args[0], "echo") == 0)
		b_echo(data->s_args);
	else if (ft_strcmp(data->s_args[0], "cd") == 0)
		b_cd(data);
	else if (ft_strcmp(data->s_args[0], "setenv") == 0)
		b_setenv(data);
	else if (ft_strcmp(data->s_args[0], "unsetenv") == 0)
		b_unsetenv(data);
	else if (ft_strcmp(data->s_args[0], "env") == 0)
		b_env(data);
	else if (ft_strcmp(data->s_args[0], "exit") == 0)
		b_exit(data);
	else if (ft_strcmp(data->s_args[0], "help") == 0)
		b_help();
}
