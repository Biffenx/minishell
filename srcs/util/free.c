/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:59:52 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/31 20:01:39 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int						free_list_env(t_data *data)
{
	t_env		*current;
	t_env		*tmp;

	current = data->enviro;
	while (current)
	{
		tmp = current->next;
		free(tmp);
		current = tmp;
	}
	return (1);
}

int						free_list_tok(t_data *data)
{
	free(data->tok->value);
	free(data->tok);
	data->tok = NULL;
	return (1);
}

int						free_list_token(t_data *data)
{
	t_tok		*current;
	t_tok		*tmp;

	current = data->token;
	while (current)
	{
		tmp = current->next;
		free(current->tokens);
		free(current);
		current = tmp;
	}
	return (1);
}

void					free_first(t_data *data)
{
	free(data->args);
	free_list_token(data);
	free_history(data);
}
