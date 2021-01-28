/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:59:02 by jwilen            #+#    #+#             */
/*   Updated: 2020/11/01 00:14:33 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void			is_up(t_data *data)
{
	if (data->history)
		if (data->history->prev)
		{
			ft_bzero(data->buff, READBUF);
			data->history = data->history->prev;
			tputs(tgetstr("cb", NULL), 1, print_c);
			write(1, "\r", 1);
			ft_memcpy(data->buff, data->history->hist,
			ft_strlen(data->history->hist) + 1);
			prompt(data);
			ft_printf("%s", data->buff);
			data->i = ft_strlen(data->buff);
		}
}

static void			is_down(t_data *data)
{
	if (data->history)
		if (data->history->next)
		{
			ft_bzero(data->buff, READBUF);
			data->history = data->history->next;
			tputs(tgetstr("cb", NULL), 1, print_c);
			write(1, "\r", 1);
			ft_memcpy(data->buff, data->history->hist,
			ft_strlen(data->history->hist) + 1);
			prompt(data);
			ft_printf("%s", data->buff);
			data->i = ft_strlen(data->buff);
		}
}

void				handle_key(t_data *data, int c)
{
	if (ft_isprint(c))
		is_print(data, c);
	else if (c == BACK)
	{
		if (data->i >= 1)
			delbuff(data);
	}
	else if (c == LEFT)
		is_left(data);
	else if (c == RIGHT)
		is_right(data);
	else if (c == UP)
		is_up(data);
	else if (c == DOWN)
		is_down(data);
	else if (c == HOME)
		is_home(data);
	else if (c == END)
		is_end(data);
	else if (c == CTRLP)
		exit(1);
}
