/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 20:27:29 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:48:48 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		is_valid_cmd(char *str)
{
	if (!ft_strcmp(str, "nick")
		|| !ft_strcmp(str, "join")
		|| !ft_strcmp(str, "leave")
		|| !ft_strcmp(str, "who")
		|| !ft_strcmp(str, "msg")
		|| !ft_strcmp(str, "msgc")
		|| !ft_strcmp(str, "help")
		|| !ft_strcmp(str, "login")
		|| !ft_strcmp(str, "invite")
		|| !ft_strcmp(str, "time")
		|| !ft_strcmp(str, "away")
		|| !ft_strcmp(str, "kick"))
		return (1);
	return (0);
}

void	go_to_cmd(t_cmd *cmd, int cs, t_env *e)
{
	if (cmd->error)
		cmd_syntax_error(cmd->error, cs, e);
	else if (!ft_strcmp(cmd->cmd, "nick"))
		cmd_nickname(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "join"))
		cmd_join(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "leave"))
		cmd_leave(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "who"))
		cmd_who(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "msg"))
		cmd_msg(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "msgc"))
		cmd_msg_chan(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "help"))
		cmd_help(cs, e);
	else if (!ft_strcmp(cmd->cmd, "invite"))
		cmd_invite(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "time"))
		cmd_time(cs, e);
	else if (!ft_strcmp(cmd->cmd, "away"))
		cmd_away(cmd, cs, e);
	else if (!ft_strcmp(cmd->cmd, "kick"))
		cmd_kick(cmd, cs, e);
}
