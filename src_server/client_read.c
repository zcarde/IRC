/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:45:12 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:31:26 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	client_read(t_env *e, int cs)
{
    int		r;
    char	buff[BUF_SIZE + 1];

    ft_bzero(buff, BUF_SIZE + 1);
    r = recv(cs, buff, BUF_SIZE, 0);
	buff[r] = 0;
	ft_strappend(e->fds[cs].buf_read, buff, BUF_SIZE);
    if (r <= 0)
    {
        close(cs);
        clean_fd(cs, e);
        debug(ft_mstrjoin(3, "client #", ft_itoa(cs), "gone away"));
    }
    else
    {
    	if (ft_strchr(e->fds[cs].buf_read, '\n'))
    		line_received(cs, e);
    }
}
