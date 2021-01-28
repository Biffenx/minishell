/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:02:00 by jwilen            #+#    #+#             */
/*   Updated: 2020/06/10 16:02:47 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstlen(t_list *list)
{
	t_list	*node;
	int		i;

	i = 0;
	node = list;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
