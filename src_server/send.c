/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 20:27:44 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:03:53 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_message(int fd, char *str, t_env *e)
{
	char	*message;

	message = ft_strjoin(str, "\n");
	ft_strappend(e->fds[fd].buf_write, message, BUF_SIZE);
}

void	send_privmessage(int fd, char *str, t_env *e)
{
	char	*privmessage;

	privmessage = ft_mstrjoin(3, "\033[33m", str, "\033[0m\n");
	ft_strappend(e->fds[fd].buf_write, privmessage, BUF_SIZE);
}

void	send_response(int fd, char *str, t_env *e)
{
	char	*response;

	response = ft_mstrjoin(3, "\033[32m", str, "\033[0m\n");
	ft_strappend(e->fds[fd].buf_write, response, BUF_SIZE);
}

void	send_kick(int fd, char *str, t_env *e)
{
	char	*error;

	error = ft_mstrjoin(3, "\033[36m", str, "\033[0m\n");
	ft_strappend(e->fds[fd].buf_write, error, BUF_SIZE);
}

void	send_error(int fd, char *str, t_env *e)
{
	char	*error;

	error = ft_mstrjoin(3, "\033[31m", str, "\033[0m\n");
	ft_strappend(e->fds[fd].buf_write, error, BUF_SIZE);
}
