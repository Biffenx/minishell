/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:51:20 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/29 12:15:32 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static char		*dbl_join(char **alfa, char **gamma)
{
	char	*ret;
	char	*ret2;

	ret = ft_strjoin(*alfa, "/");
	ret2 = ft_strjoin(ret, *gamma);
	free(ret);
	free(*gamma);
	return (ret2);
}

static char		*tilde(t_data *data, char **str)
{
	char	*tilde;
	char	*tmp;

	tilde = get_enviroment(data, "HOME");
	!tilde ? tilde = "" : 0;
	if (ft_strequ(*str, "~") || ft_strequ(*str, "~/"))
	{
		free(*str);
		*str = ft_strdup(tilde);
	}
	else
	{
		tmp = ft_strnew(ft_strlen(*str) - 2);
		ft_strncpy(tmp, *str + 2, ft_strlen(*str) + 1);
		free(*str);
		*str = dbl_join(&tilde, &tmp);
	}
	return (*str);
}

static char		*dollar(t_data *data, char **str)
{
	char	*dollar;

	dollar = get_enviroment(data, (*str + 1));
	!dollar ? dollar = "" : 0;
	free(*str);
	*str = ft_strdup(dollar);
	return (*str);
}

static void		check_tilde_dollar(t_data *data)
{
	t_tok	*current;

	current = data->token;
	while (current)
	{
		if (ft_strchr(current->tokens, '~'))
			current->tokens = tilde(data, &current->tokens);
		if (ft_strchr(current->tokens, '$'))
			current->tokens = dollar(data, &current->tokens);
		current = current->next;
	}
}

void			parse(t_data *data)
{
	check_tilde_dollar(data);
}
