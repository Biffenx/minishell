/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:29:05 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/10/31 08:53:59 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void		die(const char *s)
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	perror(s);
	exit(1);
}

void		enable_rawmode(void)
{
	struct termios tty_attr;

	tcgetattr(0, &tty_attr);
	tty_attr.c_lflag &= (~(ICANON | ECHO));
	tty_attr.c_cc[VTIME] = 0;
	tty_attr.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &tty_attr);
}

static int	read_key2(char seq[3])
{
	if (read(STDIN_FILENO, &seq[0], 1) != 1)
		return ('\x1b');
	if (read(STDIN_FILENO, &seq[1], 1) != 1)
		return ('\x1b');
	if (seq[0] == '[')
	{
		if (seq[1] == 'A')
			return (UP);
		if (seq[1] == 'B')
			return (DOWN);
		if (seq[1] == 'C')
			return (RIGHT);
		if (seq[1] == 'D')
			return (LEFT);
		if (seq[1] == 'H')
			return (HOME);
		if (seq[1] == 'F')
			return (END);
	}
	return ('\x1b');
}

int			read_key(void)
{
	int		nread;
	char	c;
	char	seq[3];
	int		ret;

	while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
	{
		if (nread == -1 && errno != EAGAIN)
			die("read");
	}
	if (c == '\x1b')
	{
		ret = read_key2(seq);
		return (ret);
	}
	else
		return (c);
}

void		keypress(t_data *data)
{
	int		c;

	ft_bzero(data->buff, 4096);
	data->i = 0;
	prompt(data);
	while (1)
	{
		c = read_key();
		if (c == ENTER)
		{
			ft_printf("\n");
			return ;
		}
		else
			handle_key(data, c);
	}
}
