/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 00:06:14 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/01 00:14:32 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		free_history(t_data *data)
{
	t_his	*tmp;

	if (!data->history)
		return ;
	while (data->history->prev)
		data->history = data->history->prev;
	while (data->history)
	{
		tmp = data->history->next;
		free(data->history->hist);
		free(data->history);
		data->history = tmp;
	}
}

int			input_just_whitespaces(t_data *data)
{
	int		i;

	i = 0;
	while (data->buff[i])
		if (!ft_strchr(" \t\n\v\f\r", data->buff[i++]))
			return (0);
	return (1);
}

int			same_as_previous_command(t_data *data)
{
	if (data->history->prev)
		data->history = data->history->prev;
	if (data->history->next)
	{
		while (data->history->next->next)
			data->history = data->history->next;
	}
	if (ft_strequ(data->buff, data->history->hist))
		return (1);
	return (0);
}

void		save_history(t_data *data)
{
	if (ft_strlen(data->buff) > 100)
		return ;
	if (data->history_fd != -1)
		if (!same_as_previous_command(data) && !input_just_whitespaces(data))
			ft_putendl_fd(data->buff, data->history_fd);
}

t_his		*new_history_node(char *str, t_his *prev)
{
	t_his	*node;

	node = (t_his*)ft_memalloc(sizeof(t_his));
	node->hist = str;
	node->prev = prev;
	node->next = NULL;
	return (node);
}
