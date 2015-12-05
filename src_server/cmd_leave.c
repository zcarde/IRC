/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_leave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:43:59 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:44:44 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_leave(t_cmd *cmd, int fd, t_env *e)
{
	t_cmd	next;

	if (!e->fds[fd].chan)
		send_error(fd, "You are not currently in a channel", e);
	else
	{
		if (cmd->args[1])
		{
			next = parse_buffer(ft_mstrjoin(3, "/msgc (Leaved) "
						, args_to_string_start(cmd->args, 1), "\n"));
			go_to_cmd(&next, fd, e);
		}
		send_response(fd, ft_strjoin("You leaved channel "
			, e->fds[fd].chan), e);
		e->fds[fd].chan = NULL;
	}
}
