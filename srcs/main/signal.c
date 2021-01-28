/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:41:50 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/05 06:38:55 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_data *g_data;

static void		handle_sig(int sig)
{
	sigset_t set;

	if (sig == SIGINT)
	{
		sigemptyset(&set);
		sigprocmask(SIG_BLOCK, &set, NULL);
		g_data->i = 0;
		ft_bzero(g_data->buff, 4096);
		ft_printf("\n");
		prompt(g_data);
		sigprocmask(SIG_UNBLOCK, &set, NULL);
	}
}

void			enable_signal(t_data *data)
{
	struct sigaction	sa;

	g_data = data;
	sa.sa_handler = handle_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
}
