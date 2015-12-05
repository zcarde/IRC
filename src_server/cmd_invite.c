/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_invite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:39:48 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:05:47 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_invite(t_cmd *cmd, int fd, t_env *e)
{
	int	dest;

	if (!cmd->args[1])
		send_error(fd, "Usage: /invite nickname", e);
	else if (!e->fds[fd].chan)
		send_error(fd, "You need to be in a channel", e);
	else
	{
		dest = get_dest_from_name(cmd->args[1], e);
		if (dest == -1)
			send_error(fd, ft_strjoin(cmd->args[1], " isn't connected"), e);
		else
		{
			send_privmessage(fd, ft_mstrjoin(4, "Invitation to channel ", e->fds[fd].chan, " to ", cmd->args[1]), e);
			send_privmessage(dest, ft_mstrjoin(4, "Invitation to channel ", e->fds[fd].chan, " from ", e->fds[fd].nickname), e);
			send_privmessage(dest, ft_mstrjoin(3, "Use /join ", e->fds[fd].chan, " to join channel"), e);
		}
	}
}
