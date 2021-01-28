/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:23:22 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/31 23:35:47 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		delbuff(t_data *data)
{
	unsigned int		len;

	len = ft_strlen(data->buff);
	tputs(tgetstr("le", NULL), 1, print_c);
	if (data->i == (len))
	{
		data->buff[len - 1] = '\0';
		tputs(tgetstr("cd", NULL), 1, print_c);
	}
	else
	{
		tputs(tgetstr("sc", NULL), 1, print_c);
		tputs(tgetstr("cd", NULL), 1, print_c);
		ft_putstr(&data->buff[data->i]);
		tputs(tgetstr("rc", NULL), 1, print_c);
		ft_memmove(&data->buff[data->i - 1],
		&data->buff[data->i], len - data->i);
		data->buff[len - 1] = '\0';
	}
	data->i -= 1;
}
