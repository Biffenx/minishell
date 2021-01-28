/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:34:38 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/29 09:51:23 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		b_env(t_data *data)
{
	t_env	*current;

	current = data->enviro;
	while (current)
	{
		ft_printf("%s\n", current->node);
		current = current->next;
	}
}
