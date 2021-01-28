/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:55:20 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/05 09:29:35 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	free_path(int i, char **path)
{
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

static char	*free_path_rest(char *check, int i, char **path)
{
	free(check);
	free(path[i]);
	check = NULL;
	return (check);
}

static char	*find_path(t_data *data, int i)
{
	struct stat	buf;
	char		**path;
	char		*check;

	if (!get_enviroment(data, "PATH"))
	{
		check = ft_strdup(data->s_args[0]);
		return (check);
	}
	path = ft_strsplit(get_enviroment(data, "PATH"), ':');
	while (path[i])
	{
		check = dbl_join_no_free(path[i], data->s_args[0]);
		if (stat(check, &buf) == 0)
		{
			free_path(i, path);
			return (check);
		}
		else
			check = free_path_rest(check, i, path);
		i++;
	}
	check = ft_strdup(data->s_args[0]);
	free(path);
	return (check);
}

static void	run_fork(t_data *data, char *path)
{
	pid_t		pid;
	int			status;
	int			ret;

	pid = fork();
	if (pid == -1)
	{
		ft_printf("can't fork, error occured\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (!check_rights(path))
			exit(0);
		ret = execve(path, data->s_args, data->enviroment);
		if (ret != 0)
		{
			ft_printf("m: command not found: %s\n", data->s_args[0]);
			free(path);
		}
		exit(0);
	}
	else
		wait(&status);
	free(path);
}

void		run(t_data *data)
{
	char		*path;

	convert_ll_to_arr_env(data);
	if (data->s_args[0] == NULL)
	{
		free(data->enviroment);
		return ;
	}
	if (!check_build(data->s_args[0]))
	{
		path = find_path(data, 0);
		run_fork(data, path);
	}
	else
		builtins(data);
	free(data->enviroment);
}
