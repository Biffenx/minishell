/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:18:02 by jwilen            #+#    #+#             */
/*   Updated: 2020/11/05 07:11:10 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int				array_len_arr(t_data *data, int i)
{
	int		len;

	len = 0;
	while (data->args[i] != NULL && !ft_strequ(data->args[i], ";"))
	{
		len++;
		i++;
	}
	return (len);
}

void			convert_ll_to_arr_env(t_data *data)
{
	int		len;
	t_env	*current;
	int		i;

	len = list_len_env(data);
	i = 0;
	current = data->enviro;
	data->enviroment = malloc(sizeof(char *) * (len + 1));
	if (!data->enviroment)
	{
		ft_printf("Malloc failed\n");
		exit(1);
	}
	while (current)
	{
		data->enviroment[i] = current->node;
		current = current->next;
		i++;
	}
	data->enviroment[i] = NULL;
}

void			convert_ll_to_arr_tok(t_data *data)
{
	int		len;
	t_tok	*current;
	int		i;

	len = list_len_tok(data);
	i = 0;
	current = data->token;
	data->args = malloc(sizeof(char *) * (len + 1));
	if (!data->args)
	{
		ft_printf("Malloc failed\n");
		exit(1);
	}
	while (current)
	{
		data->args[i] = current->tokens;
		current = current->next;
		i++;
	}
	data->args[i] = NULL;
}

void			convert_arr_tok_to_arr(t_data *data)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	while (data->args[i])
	{
		j = 0;
		len = array_len_arr(data, i);
		data->s_args = (char **)ft_memalloc(sizeof(char*) * (len + 1));
		while (len > 0)
		{
			data->s_args[j] = ft_strdup(data->args[i]);
			j++;
			i++;
			len--;
		}
		data->s_args[j] = NULL;
		run(data);
		ft_free_s_data(data);
		if (data->args[i] != NULL)
			i++;
		if (data->args[i] == NULL)
			break ;
	}
}

void			run_first(t_data *data)
{
	convert_ll_to_arr_tok(data);
	convert_arr_tok_to_arr(data);
}
