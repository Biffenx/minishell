/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:46:38 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/29 09:52:29 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	b_exit(t_data *data)
{
	free_list_token(data);
	free_list_env(data);
	ft_bzero(data->buff, 4096);
	exit(0);
}
