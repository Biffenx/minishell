/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 07:44:58 by jochumwilen       #+#    #+#             */
/*   Updated: 2020/11/04 15:50:44 by jwilen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <string.h>
# include <time.h>
# include <curses.h>
# include <dirent.h>
# include <term.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "token.h"
# include "lexer.h"

# define READBUF 4096
# define ENTER 10
# define BACK 127
# define ESC 27
# define DEL 295
# define UP 183
# define DOWN 184
# define LEFT 186
# define RIGHT 185
# define SPACE 32
# define CTRLD 4
# define CTRLP 16
# define HOME 190
# define END 188
# define TILDE 126
# define MINUS 45
# define SLASH 47
# define DOLLAR 36
# define DOT 46
# define UNDERLINE 95
# define HASH_SIZE 2900

typedef struct		s_his
{
	struct s_his	*prev;
	char			*hist;
	struct s_his	*next;
}					t_his;

typedef struct		s_env
{
	char			*node;
	struct s_env	*next;
}					t_env;

typedef struct		s_tok
{
	char			*tokens;
	struct s_tok	*next;
}					t_tok;

typedef struct		s_hash
{
	char			*hash_str;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_data
{
	t_env			*enviro;
	t_tok			*token;
	t_his			*history;
	t_hash			*hash;
	t_hash			*first[HASH_SIZE];
	char			*history_path;
	int				history_fd;
	unsigned int	i;
	int				line_his;
	char			buff[READBUF];
	char			**args;
	char			**s_args;
	char			**enviroment;
	t_token			*tok;
	int				logo;
}					t_data;

char				*ft_relloc(char **str);
char				*dbl_join_no_free(char *alfa, char *gamma);
int					check_rights(char *file);
void				logo_set(t_data *data);
void				free_first(t_data *data);
void				random_logo(t_data *data);
void				enable_rawmode(void);
void				disable_rawmode(void);
void				die(const char *s);
int					read_key(void);
void				keypress(t_data *data);
int					check_build(char *str);
void				delbuff(t_data *data);
void				config_termcaps(t_data *data);
t_data				*init_env(void);
void				read_env(t_data *data, char **env);
void				create_input(t_data *data, t_env *lst, char *str);
void				delete_env_node(t_env *lst);
void				lexi(t_data *data);
void				create_input_tok(char *str, t_data *data);
int					print_c(int c);
void				prompt(t_data *data);
void				enable_signal(t_data *data);
/*
** history functions
*/
void				init_history(t_data *data);
void				open_history_file(t_data *data);
int					file_empty(t_data *data);
void				add_history(t_data *data, char *str);
t_his				*new_history_node(char *str, t_his *prev);
int					same_as_previous_command(t_data *data);
void				free_history(t_data *data);
void				save_history(t_data *data);
int					input_just_whitespaces(t_data *data);
/*
** key presses
*/
void				handle_key(t_data *data, int c);
/*
** key presses
*/
void				parse(t_data *data);
/*
** handle enviroment changes
*/
char				*get_enviroment(t_data *data, char *str);
void				change_enviroment(t_data *data, char *str, char *input);
int					list_len_env(t_data *data);
void				run(t_data *data);
void				run_first(t_data *data);
/*
** built ins
*/
void				builtins(t_data *data);
void				b_echo(char **args);
void				b_cd(t_data	*data);
void				b_env(t_data *data);
void				b_setenv(t_data	*data);
void				b_unsetenv(t_data *data);
void				b_help(void);
void				b_exit(t_data *data);
/*
** free functions
*/
int					free_list_token(t_data *data);
int					free_list_env(t_data *data);
void				ft_free_s_data(t_data *data);
/*
** convert linked lists to arrays
*/
void				convert_ll_to_arr_tok(t_data *data);
void				convert_ll_to_arr_env(t_data *data);
int					list_len_tok(t_data *data);
/*
** cd path functions
*/
char				*b_cd_path_alfa(t_data *data, char *directory);
char				*b_cd_path_dbl(t_data *data, char *directory,
char buf[PATH_MAX]);
/*
** key presses
*/
void				is_right(t_data *data);
void				is_left(t_data *data);
void				is_print(t_data *data, int c);
void				is_home(t_data *data);
void				is_end(t_data *data);
#endif
