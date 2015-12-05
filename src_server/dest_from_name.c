/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dest_from_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 23:04:00 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:04:11 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		get_dest_from_name(char *name, t_env *e)
{
	int		i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && !ft_strcmp(e->fds[i].nickname, name))
			return (i);
		i++;
	}
	return (-1);
}
