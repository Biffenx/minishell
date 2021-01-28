/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 06:35:00 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/01 07:31:08 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int			list_len_tok(t_data *data)
{
	t_tok		*current;
	int			len;
	int			semi;

	len = 0;
	semi = 0;
	current = data->token;
	while (current)
	{
		len++;
		if (ft_strchr(current->tokens, ';'))
			semi++;
		current = current->next;
	}
	return (len);
}

int			list_len_env(t_data *data)
{
	t_env		*current;
	int			len;

	len = 0;
	current = data->enviro;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int			check_build(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "setenv") == 0)
		return (1);
	else if (ft_strcmp(str, "unsetenv") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	else if (ft_strcmp(str, "help") == 0)
		return (1);
	else
		return (0);
}

void		ft_free_s_data(t_data *data)
{
	int		i;

	i = 0;
	while (data->s_args[i])
	{
		ft_strdel(&data->s_args[i]);
		i++;
	}
	free(data->s_args);
}
