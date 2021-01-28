/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 08:26:00 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/07 11:18:36 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** Termcaps is used for moving cursor position around the screen.
** Program exits if it fails to configurate termcaps.
*/

void		config_termcaps(t_data *data)
{
	char	*type;
	char	buffer[2048];
	int		success;

	type = get_enviroment(data, "TERM");
	if (type == 0)
		ft_putendl_fd("Specify a terminal type.", STDERR_FILENO);
	success = tgetent(buffer, type);
	if (success > 0)
	{
		tputs(tgetstr("cl", NULL), 1, print_c);
		return ;
	}
	else if (success < 0)
		ft_putendl_fd("Could not access the termcap data base.", STDERR_FILENO);
	else if (success == 0)
		ft_putendl_fd("Terminal type is not defined.", STDERR_FILENO);
	exit(1);
}
