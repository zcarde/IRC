/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_received.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:14:18 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:31:11 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	cut_newline(t_fd *fd, int read)
{
	char	*str;
	char	*tmp;
	int		nl;

	if (read)
		str = fd->buf_read;
	else
		str = fd->buf_write;
	nl = ft_strchr(str, '\n') - str;
	tmp = ft_strsub(str, nl + 1, BUF_SIZE - nl);
	if (!tmp)
		ft_bzero(str, BUF_SIZE);
	else
		ft_strcpy(str, tmp);
}

void	line_received(t_env *e)
{
	t_cmd	cmd;

	cmd.error = NULL;
	cmd = parse_line(e->stdin.buf_read);
	if (cmd.cmd && !cmd.error)
	{
		if (!ft_strcmp(cmd.cmd, "connect"))
			init_server(&cmd, e);
		else if (!e->server.socket)
			print_error("You are not connected to a NeoIRC client\nUse /connect machine [port]");
		else
			do_cmd(cmd, e);
		cut_newline(&e->stdin, 1);
		if (ft_strchr(e->stdin.buf_read, '\n'))
			line_received(e);
	}
}

void	line_received_from_server(t_env *e)
{
	ft_strappend(e->stdin.buf_write, e->srv.buf_read, BUF_SIZE);
	ft_bzero(e->srv.buf_read, BUF_SIZE);
}
