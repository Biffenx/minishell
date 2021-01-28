/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_key2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:01:34 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/30 13:07:26 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			is_end(t_data *data)
{
	unsigned int len;

	len = ft_strlen(data->buff);
	while (data->i < len)
	{
		tputs(tgetstr("nd", NULL), 1, print_c);
		data->i += 1;
	}
}

void			is_home(t_data *data)
{
	while (data->i > 0)
	{
		tputs(tgetstr("le", NULL), 1, print_c);
		data->i -= 1;
	}
}

void			is_print(t_data *data, int c)
{
	if (ft_strlen(data->buff) == data->i)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		ft_strcat(data->buff, (const char *)&c);
		data->i += 1;
	}
	else
	{
		ft_memmove(&data->buff[data->i + 1], &data->buff[data->i],
		ft_strlen(data->buff) - data->i);
		ft_putchar_fd(c, STDOUT_FILENO);
		tputs(tgetstr("sc", NULL), 1, print_c);
		ft_putstr(&data->buff[data->i + 1]);
		tputs(tgetstr("rc", NULL), 1, print_c);
		data->buff[data->i] = c;
		data->i += 1;
	}
}

void			is_left(t_data *data)
{
	if (data->i > 0)
	{
		tputs(tgetstr("le", NULL), 1, print_c);
		data->i -= 1;
	}
}

void			is_right(t_data *data)
{
	if (data->i <= ft_strlen(data->buff) - 1 && data->buff[data->i] != 0)
	{
		tputs(tgetstr("nd", NULL), 1, print_c);
		data->i += 1;
	}
}
