/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 22:24:52 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:17:22 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define FD_FREE		0
# define FD_SERV		1
# define FD_CLIENT		2

# define BUF_SIZE		4096

# define CMD_MAX_SIZE	7
# define NICKNAME_SIZE	9

# define MAX(a,b)	((a > b) ? a : b)

# include "libft.h"
# include "struct_serv.h"
# include <time.h>
# include <sys/select.h>
# include <sys/resource.h>
# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

/*
**	send.c
*/
void	send_message(int fd, char *str, t_env *e);
void	send_privmessage(int fd, char *str, t_env *e);
void	send_response(int fd, char *str, t_env *e);
void	send_kick(int fd, char *str, t_env *e);
void	send_error(int fd, char *str, t_env *e);

/*
**	parsing.c
*/
void	get_cmd(char *str, t_cmd *cmd);
void	get_args(char *data, t_cmd *cmd);
t_cmd	parse_buffer(char *data);

/*
**	nickname.c
*/
int		already_exist(char *nick, t_env *env);
int		is_valid_nickname(char *nick);

/*
**	main_loop.c
*/
void	check_fd(t_env *e);
void	clean_fd(int cs, t_env *e);
void	main_loop(t_env *e);

/*
**	line_functions.c
*/
char	*args_to_string_start(char **args, int start);
void	trim_end_buffer(char *str);
void	cut_newline(t_fd *fd);
void	line_received(int cs, t_env *e);

/*
**	inits.c
*/
void	init_env(t_env *e);
void	init_fd(t_env *e);
void	srv_accept(t_env *e, int s);
int		srv_create(t_env *e, int port);

/*
**	error.c
*/
void	exit_error(char *str, int err);

/*
**	dest_from_name.c
*/
int		get_dest_from_name(char *name, t_env *e);

/*
**	debug.c
*/
void	debug(char *str);

/*
**	commandes.c
*/
int		is_valid_cmd(char *str);
void	go_to_cmd(t_cmd *cmd, int cs, t_env *e);

/*
**	cmd_who.c
*/
void	cmd_who(t_cmd *cmd, int fd, t_env *env);

/*
**	cmd_time.c
*/
void	cmd_time(int fd, t_env *e);

/*
**	cmd_syn_error.c
*/
void	cmd_syntax_error(char *error, int fd, t_env *e);

/*
**	cmd_nick.c
*/
void	cmd_nickname(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_msg.c
*/
void	cmd_msg(t_cmd *cmd, int fd, t_env *e);
void	cmd_msg_chan(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_login.c
*/
void	cmd_login(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_leave.c
*/
void	cmd_leave(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_kick.c
*/
void	cmd_kick(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_join.c
*/
void	cmd_join(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_invite.c
*/
void	cmd_invite(t_cmd *cmd, int fd, t_env *e);

/*
**	cmd_help.c
*/
void	cmd_help(int fd, t_env *e);

/*
**	cmd_away.c
*/
void	cmd_away(t_cmd *cmd, int fd, t_env *e);

/*
**	client_write.c
*/
void	client_write(t_env *e, int cs);

/*
**	client_read.c
*/
void	client_read(t_env *e, int cs);

#endif
