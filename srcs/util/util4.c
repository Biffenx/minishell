/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:52:12 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/30 16:11:19 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char		*dbl_join_no_free(char *alfa, char *gamma)
{
	char	*ret;
	char	*ret2;

	ret = ft_strjoin(alfa, "/");
	ret2 = ft_strjoin(ret, gamma);
	free(ret);
	return (ret2);
}
