/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:34:29 by jwilen            #+#    #+#             */
/*   Updated: 2020/11/01 00:15:06 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		add_history(t_data *data, char *str)
{
	if (!data->history)
		data->history = new_history_node(str, NULL);
	else
	{
		data->history->next = new_history_node(str, data->history);
		data->history = data->history->next;
	}
}

int			file_empty(t_data *data)
{
	struct stat		buff;

	if (stat(data->history_path, &buff))
		return (1);
	if (buff.st_size <= 1)
		return (1);
	return (0);
}

void		open_history_file(t_data *data)
{
	char	*str;

	data->history = NULL;
	data->history_fd = open(data->history_path,
		O_RDWR | O_APPEND | O_CREAT, 0666);
	if (data->history_fd == -1)
		return ;
	if (!file_empty(data))
	{
		while (get_next_line(data->history_fd, &str) > 0)
			add_history(data, str);
	}
	add_history(data, ft_strdup(""));
}

void		init_history(t_data *data)
{
	char	*path;

	path = (char*)ft_memalloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX);
	path = ft_strjoin_free(path, ft_strdup("/.mini_history"));
	data->history_path = path;
	data->history_fd = 0;
	free(path);
	open_history_file(data);
}
