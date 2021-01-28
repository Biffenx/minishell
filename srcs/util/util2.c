/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:21:32 by jwilen            #+#    #+#             */
/*   Updated: 2020/11/01 07:31:01 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char			**print_s(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	ft_putendl("JO");
	return (NULL);
}

t_data			*init_env(void)
{
	t_data *data;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	!data ? exit(1) : 0;
	data->enviro = NULL;
	return (data);
}

int				print_c(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

void			read_env(t_data *data, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		create_input(data, data->enviro, env[i]);
		i++;
	}
}

void			delete_env_node(t_env *lst)
{
	t_env		*tmp;

	free(lst->next->node);
	tmp = lst->next;
	lst->next = lst->next->next;
	free(tmp);
}
