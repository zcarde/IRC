/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:59:59 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:07:24 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_fd(t_env *e)
{
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	FD_SET(STDIN, &e->fd_read);
	FD_SET(e->server.socket, &e->fd_read);
	if (ft_strlen(e->srv.buf_write) > 0)
 		FD_SET(e->server.socket, &e->fd_write);
 	if (ft_strlen(e->stdin.buf_write) > 0)
 		FD_SET(STDIN, &e->fd_write);
}

void	init_server(t_cmd *cmd, t_env *env)
{
	if (env->server.socket)
	{
		print_error("You are already connected to an IRC server");
		return ;
	}
	if (!cmd->args[0] || !cmd->args[1])
		print_error("Usage: /connect machine [port]");
	else
	{
		if (!cmd->args[2])
			env->server.port = 6667;
		else if (ft_is_str_number(cmd->args[2]))
			env->server.port = atoi(cmd->args[2]);
		if (!ft_strcmp("localhost", cmd->args[1]))
			env->server.sin.sin_addr.s_addr = inet_addr("127.0.0.1");
		else
			env->server.sin.sin_addr.s_addr = inet_addr(cmd->args[1]);
		if (env->server.port && env->server.sin.sin_addr.s_addr)
			create_server(env);
	}
}

void	init_logs(t_env *e)
{
	mode_t	mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	e->logfd = open("./logs.txt", O_WRONLY | O_CREAT | O_APPEND, mode);
	if (e->logfd == -1)
		exit_error("Can't create/open log file (log.txt)", -1);
}

void	create_server(t_env *env)
{
	struct protoent		*proto;

	proto = getprotobyname("tcp");
	if (!proto)
		print_error("Unable to find tcp protocol\n");
	env->server.socket = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	env->server.sin.sin_family = AF_INET;
	env->server.sin.sin_port = htons(env->server.port);
	if (connect(env->server.socket,
		(const struct sockaddr *)&env->server.sin,
		sizeof(env->server.sin)) == -1)
	{
		env->server.socket = 0;
		print_error("Connect error");
	}
	else
	{
		print_info("Successfuly connected to the irc server");
		init_logs(env);
	}
}
