/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_who.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:37:37 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:38:06 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_who(t_cmd *cmd, int fd, t_env *env)
{
	int		i;

	if (cmd->args[1])
		send_error(fd, "Usage: /who", env);
	else if (env->fds[fd].chan == NULL)
		send_error(fd, "You can use /who only in channels", env);
	else
	{
		send_response(fd, ft_mstrjoin(3, "Users in ", env->fds[fd].chan, ":"), env);
		i = 0;
		while (i < env->maxfd)
		{
			if (env->fds[i].chan && !ft_strcmp(env->fds[i].chan, env->fds[fd].chan))
				send_response(fd, ft_strjoin("\t- ", env->fds[i].nickname), env);
			i++;
		}
	}
}
