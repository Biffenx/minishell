/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:47:01 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/02 12:54:55 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	b_help2(void)
{
	ft_putendl("----------------------------------------");
	ft_printf(BLUE"     Path commands:\n"YELLOW);
	ft_putendl("chmod - change file modes or Access Control Lists");
	ft_putendl("cat - concatenate and print files");
	ft_putendl("cp -- copy files");
	ft_putendl("date - display or set date and time");
	ft_putendl("dash - command interpreter (shell)");
	ft_putendl("[ - condition evaluation utility");
	ft_putendl("ksh - KornShell");
	ft_putendl("mkdir - make directories");
	ft_putendl("rm, unlink - remove directory entries");
	ft_putendl("sync - force completion of pending disk writes (flush cache)");
	ft_putendl("tcsh - C shell with file name completion");
	ft_putendl("date - display or set date and time");
	ft_putendl("dd - convert and copy a file");
	ft_putendl("df - display free disk space");
	ft_putendl("ed, red - text editor");
	ft_putendl("expr - evaluate expression");
	ft_putendl("hostname - set or print name of current host system");
	ft_printf("\n"RESET);
}

void		b_help(void)
{
	ft_printf(RED"*** C O M M A N D S : ****\n");
	ft_printf(BLUE"        Buildins:\n"YELLOW);
	ft_putendl("exit - exits the shell");
	ft_putendl("env - printd out the enviroment varaibles");
	ft_putendl("setenv - set enviroment varaible");
	ft_putendl("unsetenv - removes enviroment varaible");
	ft_putendl("cd - change directory");
	ft_putendl("echo - print out on STD text");
	b_help2();
}
