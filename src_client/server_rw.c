/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_rw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:05:24 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:02:44 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	server_write(t_env *e)
{
	int		ret;

	ret = send(e->server.socket, e->srv.buf_write, ft_strlen(e->srv.buf_write) + 1, 0);
	ft_bzero(e->srv.buf_write, ft_strlen(e->srv.buf_write));
}

void	server_read(t_env *e)
{
	char	buff[BUF_SIZE];

	int		ret;
	ret = recv(e->server.socket, buff, BUF_SIZE + 1, 0);
	if (ret >= 0)
		buff[ret] = 0;
	if (ret == -1 || ret == 0)
	{
		print_error("Server isn't joinable\nClosing connection...");
		close(e->server.socket);
		close(e->logfd);
		e->server.socket = 0;
		return ;
	}
	ft_strappend(e->srv.buf_read, buff, BUF_SIZE);
	if (ft_strchr(e->srv.buf_read, '\n'))
		line_received_from_server(e);
}
