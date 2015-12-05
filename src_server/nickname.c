/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nickname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:56:43 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:56:49 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		already_exist(char *nick, t_env *env)
{
	int		tmp;

	tmp = 0;
	while (tmp < env->maxfd)
	{
		if (!ft_strcmp(env->fds[tmp].nickname, nick))
			return (1);
		tmp++;
	}
	return (0);
}

int		is_valid_nickname(char *nick)
{
	if (ft_strlen(nick) > NICKNAME_SIZE)
		return (0);
	return (1);
}
