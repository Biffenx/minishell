/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:01:31 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/30 06:33:23 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		b_setenv_just(t_data *data)
{
	t_env *current;

	current = data->enviro;
	while (current)
	{
		ft_printf("%s\n", current->node);
		current = current->next;
	}
}

static void		b_setenv_var(t_data *data)
{
	change_enviroment(data, data->s_args[1], "");
}

static void		b_setenv_all(t_data *data)
{
	change_enviroment(data, data->s_args[1], data->s_args[2]);
}

void			b_setenv(t_data *data)
{
	int len;

	len = 0;
	while (data->s_args[len])
		len++;
	if (len == 1)
		b_setenv_just(data);
	else if (len > 3)
		ft_printf("cd: string not in pwd: %s\n", data->s_args[1]);
	else if (len == 2)
		b_setenv_var(data);
	else if (len == 3)
		b_setenv_all(data);
	else
		ft_printf("ms: no such file or directory: %s\n", data->s_args[1]);
}
