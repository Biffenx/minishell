/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:31:18 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/05 10:13:59 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		check_rights(char *file)
{
	struct stat	s;

	if (lstat(file, &s) == -1)
		return (2);
	if ((s.st_mode & S_IXUSR) || (s.st_mode & S_IXGRP))
		return (1);
	ft_printf("permission denied: %s\n", ft_strrchr(file, '/') + 1);
	return (0);
}
