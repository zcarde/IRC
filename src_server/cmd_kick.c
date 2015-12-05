/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_kick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:42:41 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:42:47 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_kick(t_cmd *cmd, int fd, t_env *e)
{
	int		i;

	if (!cmd->args[1])
		send_error(fd, "Usage: /kick nickname [message]", e);
	else if (!e->fds[fd].chan)
		send_error(fd, "You need to be in a channel", e);
	else if (!ft_strcmp(cmd->args[1], e->fds[fd].nickname))
		send_error(fd, "You can't kick yourself", e);
	else
	{
		i = 0;
		while (i < e->maxfd)
		{
			if ((e->fds[i].type == FD_CLIENT) && e->fds[i].chan && !ft_strcmp(e->fds[i].chan, e->fds[fd].chan)
				&& !ft_strcmp(e->fds[i].nickname, cmd->args[1]))
			{
				e->fds[i].chan = NULL;
				send_kick(i, ft_strjoin(ft_strjoin(ft_strjoin("You've been kicked from ", e->fds[fd].chan), " by "), e->fds[fd].nickname), e);
				if (cmd->args[2])
					send_kick(i, ft_strjoin("[", ft_strjoin(args_to_string_start(cmd->args, 2), "]")), e);
				return ;
			}
			i++;
		}
		send_error(fd, ft_strjoin(cmd->args[1], " isn't in your channel or isn't connected"), e);
	}
}
