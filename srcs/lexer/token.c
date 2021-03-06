/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:54:12 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/30 13:13:09 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include "../includes/token.h"
#include <stdlib.h>

t_token				*init_token(int type, char *value)
{
	t_token			*token;

	token = (t_token*)malloc(sizeof(t_token));
	!token ? exit(1) : 0;
	token->type = type;
	token->value = value;
	return (token);
}

static t_tok		*create_node_tok(char *str)
{
	t_tok	*node;

	if (!(node = (t_tok *)malloc(sizeof(t_tok))))
		exit(1);
	node->tokens = (char*)str;
	node->next = NULL;
	return (node);
}

void				create_input_tok(char *str, t_data *data)
{
	t_tok *current;

	if (!data->token)
	{
		current = create_node_tok(str);
		data->token = current;
	}
	else
	{
		current = data->token;
		while (current->next != NULL)
			current = current->next;
		current->next = create_node_tok(str);
	}
}
