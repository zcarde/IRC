/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:36:22 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:37:26 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_join(t_cmd *cmd, int fd, t_env *e)
{
	t_cmd	next;

	if (!cmd->args[1] || cmd->args[1][0] != '#')
		send_error(fd, "Usage: /join #channel", e);
	else if (e->fds[fd].chan && !ft_strcmp(e->fds[fd].chan, cmd->args[1]))
		send_error(fd, ft_strjoin("Error: You already are in channel ", e->fds[fd].chan), e);
	else
	{
		e->fds[fd].chan = ft_strdup(cmd->args[1]);
		send_response(fd, ft_strjoin("You joined channel ", e->fds[fd].chan), e);
		next = parse_buffer("/msgc (joined)\n");
		go_to_cmd(&next, fd, e);
	}
}
