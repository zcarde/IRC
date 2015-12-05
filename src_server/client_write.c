/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:47:46 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:31:30 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	client_write(t_env *e, int cs)
{
	send(cs, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write) + 1, 0);
	ft_bzero(e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write));
}
