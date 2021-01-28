/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:02:42 by jwilen            #+#    #+#             */
/*   Updated: 2020/11/04 15:30:41 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	b_cd_minus(t_data *data)
{
	char	*directory;
	char	*show;
	int		len;
	char	buf[PATH_MAX + 1];

	directory = ft_strdup(get_enviroment(data, "OLDPWD"));
	change_enviroment(data, "PWD", directory);
	change_enviroment(data, "OLDPWD", getcwd(buf, PATH_MAX + 1));
	chdir(directory);
	len = ft_strlen(get_enviroment(data, "HOME"));
	if (ft_strnequ(get_enviroment(data, "PWD"), get_enviroment(data, "HOME"),
		len) != 0 && !ft_strequ(directory, "/"))
		show = ft_strjoin_free(ft_strdup("~"),
		ft_strsub(get_enviroment(data, "PWD"), len,
		(ft_strlen(get_enviroment(data, "PWD")) - len)));
	else
		show = get_enviroment(data, "PWD");
	ft_printf("%s\n", show);
	free(directory);
	!ft_strncmp(show, "~", 1) ? free(show) : 0;
}

static void	b_cd_just(t_data *data)
{
	char	*directory;
	int		ret;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	directory = ft_strdup(get_enviroment(data, "HOME"));
	change_enviroment(data, "PWD", directory);
	change_enviroment(data, "OLDPWD", tmp);
	free(tmp);
	ft_printf("\n");
	ret = chdir(directory);
	if (ret != 0)
		ft_printf("\nError in setting PATH\n");
	free(directory);
}

static void	b_cd_path(t_data *data)
{
	char		*directory;
	char		*not;
	char		buf[PATH_MAX + 1];
	struct stat buffer;

	directory = NULL;
	not = get_enviroment(data, "OLDPWD");
	change_enviroment(data, "OLDPWD", getcwd(buf, PATH_MAX + 1));
	if (ft_strcmp(data->s_args[1], "..") == 0 ||
	(ft_strcmp(data->args[1], "/") == 0))
		directory = b_cd_path_dbl(data, directory, buf);
	else
	{
		if (!check_rights(data->s_args[1]))
			return ;
		if (stat(data->s_args[1], &buffer) == 0 && S_ISDIR(buffer.st_mode))
			directory = b_cd_path_alfa(data, directory);
		else
		{
			ft_printf("ms: no such file or directory: %s\n", data->s_args[1]);
			change_enviroment(data, "OLDPWD", not);
			return ;
		}
	}
	change_enviroment(data, "PWD", directory);
}

void		b_cd(t_data *data)
{
	int len;

	len = 0;
	while (data->s_args[len])
		len++;
	if (len == 1)
		b_cd_just(data);
	else if (len > 2)
		ft_printf("\ncd: string not in pwd: %s\n", data->s_args[1]);
	else if (ft_strcmp(data->s_args[1], "-") == 0)
		b_cd_minus(data);
	else if (data->s_args[1])
		b_cd_path(data);
	else
		ft_printf("\nms: no such file or directory: %s\n", data->s_args[1]);
}
