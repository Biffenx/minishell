/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:04:37 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/30 16:13:04 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static t_env	*create_node(char *str)
{
	t_env	*node;

	if (!(node = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	node->node = ft_strdup(str);
	node->next = NULL;
	return (node);
}

void			create_input(t_data *data, t_env *lst, char *str)
{
	t_env *current;

	if (!lst)
	{
		current = create_node(str);
		data->enviro = current;
	}
	else
	{
		current = data->enviro;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = create_node(str);
	}
}

static void		change_enviroment_set(t_data *data, t_env *current,
char *new_node, char *input)
{
	char		*new_node_2;

	new_node_2 = ft_strjoin(new_node, input);
	create_input(data, current, new_node_2);
	free(new_node);
	free(new_node_2);
}

void			change_enviroment(t_data *data, char *str, char *input)
{
	t_env		*current;
	char		*new_node;
	int			i;

	current = data->enviro;
	i = 1;
	while (current)
	{
		if (current->next && ft_strnequ(str, current->next->node, 3))
		{
			delete_env_node(current);
			new_node = ft_strjoin(str, "=");
			change_enviroment_set(data, current, new_node, input);
			i = 2;
			break ;
		}
		current = current->next;
	}
	current = data->enviro;
	if ((ft_strnequ(data->s_args[0], "set", 3) == 1) && (i == 1))
	{
		new_node = ft_strjoin(str, "=");
		change_enviroment_set(data, current, new_node, input);
	}
}

char			*get_enviroment(t_data *data, char *str)
{
	t_env		*current;

	current = data->enviro;
	while (current)
	{
		if (ft_strnequ(str, current->node, 3))
			return (ft_strrchr(current->node, '=') + 1);
		current = current->next;
	}
	return (0);
}
