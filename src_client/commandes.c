/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:00:22 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:16:18 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
		|| !ft_strcmp(str, "connect")
		|| !ft_strcmp(str, "away")
		|| !ft_strcmp(str, "quit"))
		return (1);
	return (0);
}

void	do_cmd(t_cmd cmd, t_env *e)
{
	if (!ft_strcmp(cmd.cmd, "quit"))
		exit_properly(e);
	else
	{
		if(!ft_strcmp(cmd.cmd, "msgc"))
			send_cmd_msgc(cmd, e);
		else
			send_cmd(cmd, e);
	}
}
