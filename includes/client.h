/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 22:24:46 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:12:42 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define FD_FREE		0
# define FD_SERV		1
# define FD_CLIENT		2

# define STDIN			0

# define BUF_SIZE		4096

# define READ_SIZE		7

# define CMD_MAX_SIZE	8

# include "libft.h"
# include <sys/select.h>
# include <sys/resource.h>
# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <signal.h>

typedef struct	s_cmd
{
	char	cmd[CMD_MAX_SIZE];
	char	**args;
	char	*error;
}				t_cmd;

typedef struct	s_fd
{
	int		type;
	char	*chan;
	void	(*fct_read)();
	void	(*fct_write)();
	char	buf_read[BUF_SIZE + 1];
	char	buf_write[BUF_SIZE + 1];

}				t_fd;

typedef struct			s_srv
{
	int					socket;
	struct sockaddr_in	sin;
	int					port;
	unsigned int		cslen;
}						t_srv;

typedef struct			s_env
{
	t_srv				server;
	int					logfd;
	t_fd				stdin;
	t_fd				srv;	
	fd_set				fd_read;
	fd_set				fd_write;
}						t_env;

/*
**	stdin_write.c
*/
void	stdin_read(t_env *e);
void	stdin_write(t_env *e);

/*
**	server_rw.c
*/
void	server_write(t_env *e);
void	server_read(t_env *e);

/*
**	send_command.c
*/
void	send_cmd(t_cmd cmd, t_env *e);
void	send_cmd_msgc(t_cmd cmd, t_env *e);

/*
**	prints.c
*/
void	print_msg(char *msg);
void	print_error(char *error);
void	print_info(char *info);

/*
**	parsing.c
*/
void	get_cmd(char *str, t_cmd *cmd);
void	get_args(char *data, t_cmd *cmd);
t_cmd	parse_line(char *data);

/*
**	line_received.c
*/
void	cut_newline(t_fd *fd, int read);
void	line_received(t_env *e);
void	line_received_from_server(t_env *e);

/*
**	inits.c
*/
void	init_fd(t_env *e);
void	init_server(t_cmd *cmd, t_env *env);
void	init_logs(t_env *e);
void	create_server(t_env *env);
/*
**	exit.c
*/
void	exit_properly(t_env *e);

/*
**	error.c
*/
void	exit_error(char *str, int err);

/*
**	commandes.c
*/
int		is_valid_cmd(char *str);
void	do_cmd(t_cmd cmd, t_env *e);

/*
** clean_fd.c
*/
void	clean_fd(t_fd *fd, int srv);

#endif