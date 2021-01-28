/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:13:32 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/30 16:18:08 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** DESCRIPTION
** The unsetenv() function shall remove an environment variable from the
** environment of the calling process. The name argument points to a string,
** which is the name of the variable to be removed. The named argument
** shall not contain an '=' character. If the named variable does not
** exist in the current environment, the environment shall be unchanged
** and the function is considered to have completed successfully.
*/

static void	b_unsetenv_action(t_data *data)
{
	t_env *current;

	current = data->enviro;
	while (current)
	{
		if (current->next &&
		ft_strnequ(data->s_args[1], current->next->node, 3))
			delete_env_node(current);
		current = current->next;
	}
}

void		b_unsetenv(t_data *data)
{
	int len;

	len = 0;
	while (data->s_args[len])
		len++;
	if (len != 2)
		ft_printf("unsetenv: invalid arguments\n");
	else
		b_unsetenv_action(data);
}
