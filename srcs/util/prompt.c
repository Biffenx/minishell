/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:24:31 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/30 13:10:38 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		prompt_date(void)
{
	time_t	today;
	char	hostname[READBUF];

	today = time(NULL);
	gethostname(hostname, READBUF);
	*ft_strchr(hostname, DOT) = '\0';
	ft_printf(WHITE"{"YELLOW"%.2s-", ctime(&today) + 8);
	ft_printf("%.3s-", ctime(&today) + 4);
	ft_printf("%.2s ", ctime(&today) + 22);
	ft_printf("%.5s", ctime(&today) + 11);
	ft_printf(WHITE"}"GREEN"%s"WHITE":", hostname);
}

static char		*prompt_strstr(char *pwd, char *home, char *user)
{
	pwd = ft_strsub(pwd, ft_strlen(home), (ft_strlen(pwd) - ft_strlen(home)));
	ft_dprintf(STDERR_FILENO, CYAN "~%s "RED"%s", pwd, user);
	ft_putstr_fd(WHITE"% "RESET, STDERR_FILENO);
	free(pwd);
	return (pwd);
}

void			prompt(t_data *data)
{
	t_env	*current;
	char	*pwd;
	char	*user;
	char	*home;

	prompt_date();
	current = data->enviro;
	while (current)
	{
		if (ft_strnequ("PWD", current->node, 3))
			pwd = (ft_strrchr(current->node, '=') + 1);
		if (ft_strnequ("LOGNAME", current->node, 7))
			user = (ft_strrchr(current->node, '=') + 1);
		if (ft_strnequ("HOME", current->node, 4))
			home = (ft_strrchr(current->node, '=') + 1);
		current = current->next;
	}
	if (ft_strstr(pwd, home))
	{
		pwd = prompt_strstr(pwd, home, user);
		return ;
	}
	ft_dprintf(STDERR_FILENO, CYAN "%s "RED"%s", pwd, user);
	ft_putstr_fd(WHITE"% "RESET, STDERR_FILENO);
}
