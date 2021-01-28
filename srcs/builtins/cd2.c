/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 08:22:19 by jwilen            #+#    #+#             */
/*   Updated: 2020/10/30 13:05:13 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char		*b_cd_path_dbl(t_data *data, char *directory, char buf[PATH_MAX])
{
	int		ret;

	if (ft_strequ(data->s_args[1], ".."))
		ret = chdir("..");
	else
		ret = chdir("/");
	if (ret != 0)
	{
		ft_printf("\nError in setting PATH\n");
		exit(1);
	}
	directory = getcwd(buf, PATH_MAX + 1);
	return (directory);
}

char		*b_cd_path_alfa(t_data *data, char *directory)
{
	char	buf[PATH_MAX + 1];
	char	*cwd;

	cwd = getcwd(buf, PATH_MAX + 1);
	if (ft_strequ(data->s_args[1], "."))
		directory = ft_strdup(cwd);
	else
	{
		chdir(data->s_args[1]);
		directory = getcwd(buf, PATH_MAX + 1);
	}
	return (directory);
}
