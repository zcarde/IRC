/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_away.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:42:24 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:42:33 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_away(t_cmd *cmd, int fd, t_env *e)
{
	if (!cmd->args[1])
	{
		e->fds[fd].away = NULL;
		send_response(fd, "You'r back", e);
	}
	else
	{
		e->fds[fd].away = args_to_string_start(cmd->args, 1);
		send_response(fd, "You'r now away", e);
	}
}
