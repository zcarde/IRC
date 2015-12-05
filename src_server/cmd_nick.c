/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:36:06 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:36:15 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_nickname(t_cmd *cmd, int fd, t_env *e)
{
	if (!cmd->args[1])
		send_error(fd, "Usage: /nick nickname", e);
	else if (ft_strlen(cmd->args[1]) > NICKNAME_SIZE)
		send_error(fd, "Nickname too long", e);
	else if (!is_valid_nickname(cmd->args[1]))
		send_error(fd, "Nickname invalid [a-zA-Z0-9-_]", e);
	else if (already_exist(cmd->args[1], e))
		send_error(fd, ft_strjoin(cmd->args[1], " already used"), e);
	else
	{
		ft_strcpy(e->fds[fd].nickname, cmd->args[1]);
		send_response(fd, ft_strjoin("Your nickname is now :", cmd->args[1]), e);
	}
}
