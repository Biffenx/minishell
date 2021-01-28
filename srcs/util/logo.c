/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:39:32 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/01 00:05:32 by jochumwilen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		logo3(void)
{
	ft_printf(RED" __  __ _       _     _          _ _ \n");
	ft_printf("|  \\/  (_)     (_)   | |        | | |\n");
	ft_printf("| \\  / |_ _ __  _ ___| |__   ___| | |\n");
	ft_printf("| |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |\n");
	ft_printf("| |  | | | | | | \\__ \\ | | |  __/ | |\n");
	ft_printf("|_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|");
	ft_printf(YELLOW "  (c) jwilen\n\n");
	ft_printf(RESET);
}

static void		logo2(void)
{
	ft_printf(CYAN"    _/      _/  _/            _/    _/_/_/");
	ft_printf("  _/                  _/  _/   \n");
	ft_printf("   _/_/  _/_/      _/_/_/        _/        _/_/_/");
	ft_printf("      _/_/    _/  _/    \n");
	ft_printf("  _/  _/  _/  _/  _/    _/  _/    _/_/    _/    _/");
	ft_printf("  _/_/_/_/  _/  _/     \n");
	ft_printf(" _/      _/  _/  _/    _/  _/        _/  _/    _/  _/");
	ft_printf("        _/  _/      \n");
	ft_printf("_/      _/  _/  _/    _/  _/  _/_/_/    _/    _/    _/");
	ft_printf("_/_/  _/  _/       ");
	ft_printf(YELLOW "  (c) jwilen\n\n");
	ft_printf(RESET);
}

static void		logo(void)
{
	ft_putendl("          ´´´´´´´´");
	ft_putendl("      ´´´´´´´´´*******");
	ft_putendl("   ´´´´´´´´´´***********");
	ft_putendl("  ´´´´´´´          *******");
	ft_printf(" ´´´´´´´  ");
	ft_printf(BLUE "MM   MM   ");
	ft_printf(RESET "*******\n");
	ft_printf("´´´´´´´   ");
	ft_printf(BLUE "M M M M    ");
	ft_printf(RESET "*******\n");
	ft_printf("´´´´´´´   ");
	ft_printf(BLUE "M  M  M    ");
	ft_printf(RESET "*******\n");
	ft_printf("´´´´´´´   ");
	ft_printf(BLUE "M     M    ");
	ft_printf(RESET "*******\n");
	ft_printf(" ´´´´´´   ");
	ft_printf(BLUE "M     M    ");
	ft_printf(RESET "******\n");
	ft_putendl("  ´´´´´´            ******");
	ft_putendl("    ´´´´´´´´´´´´´´******");
	ft_putendl("       ´´´´´´´´*******");
	ft_printf("           ********");
	ft_printf(YELLOW "                      (c) jwilen\n\n");
}

void			random_logo(t_data *data)
{
	int	number;
	int lower;
	int	upper;

	lower = 0;
	upper = 3;
	srand(time(NULL));
	number = (rand() % (upper - lower + 1)) + lower;
	data->logo = number;
}

void			logo_set(t_data *data)
{
	random_logo(data);
	if (data->logo == 0)
		return ;
	else if (data->logo == 1)
		logo();
	else if (data->logo == 2)
		logo2();
	else if (data->logo == 3)
		logo3();
}
