/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:38:15 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:06:04 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_msg(t_cmd *cmd, int fd, t_env *e)
{
	int		dest;
	char	*message;

	if (!cmd->args[1] || !cmd->args[2])
		send_error(fd, "Usage: /msg <nick> <message>", e);
	else
	{
		dest = get_dest_from_name(cmd->args[1], e);
		if (dest == -1)
			send_error(fd, ft_strjoin(cmd->args[1], " isn't connected"), e);
		else
		{
			message = args_to_string_start(cmd->args, 2);
			send_privmessage(fd, ft_mstrjoin(4, "Privage message to ", cmd->args[1], " : ", message), e);
			if (e->fds[dest].away)
				send_privmessage(fd, ft_mstrjoin(4, "Away response from ", e->fds[fd].nickname, " : ", e->fds[dest].away), e);
			else
				send_privmessage(dest, ft_mstrjoin(4, "Private message from ", e->fds[fd].nickname, ": ", message), e);
		}
	}
}

void	cmd_msg_chan(t_cmd *cmd, int fd, t_env *e)
{
	int		i;
	char	*message;

	if (!cmd->args[1])
		send_error(fd, "Usage: /msgc <message>", e);
	else
	{
		if (!e->fds[fd].chan)
			send_error(fd, "You are not in a channel", e);
		else
		{
			message = args_to_string_start(cmd->args, 1);
			send_message(fd, ft_mstrjoin(3, e->fds[fd].nickname, ": ", message), e);
			i = 0;
			while (i < e->maxfd)
			{
				if ((e->fds[i].type == FD_CLIENT) && e->fds[i].chan && !ft_strcmp(e->fds[i].chan, e->fds[fd].chan)
					&& ft_strcmp(e->fds[i].nickname, e->fds[fd].nickname))
					send_message(i, ft_mstrjoin(3, e->fds[fd].nickname, ": ", message), e);
				i++;
			}
		}
	}
}
