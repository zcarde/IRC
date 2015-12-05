/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_login.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:49:07 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:49:17 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_login(t_cmd *cmd, int fd, t_env *e)
{
	if (!cmd->args[1])
		send_error(fd, "Usage: /login username", e);
	else if (ft_strlen(cmd->args[1]) > NICKNAME_SIZE)
		send_error(fd, "Username too long", e);
	else if (!is_valid_nickname(cmd->args[1]))
		send_error(fd, "Username invalid [a-zA-Z0-9-_]", e);
	else if (already_exist(cmd->args[1], e))
		send_error(fd, ft_strjoin(cmd->args[1], " already used"), e);
	else
	{
		ft_strcpy(e->fds[fd].nickname, cmd->args[1]);
		send_response(fd, ft_strjoin("Successfuly logged in with username: ", cmd->args[1]), e);
		e->fds[fd].logged = 1;
	}
}
