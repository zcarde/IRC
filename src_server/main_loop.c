/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:59:10 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:59:08 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	check_fd(t_env *e)
{
	int	i;

	i = 0;
	while ((i < e->maxfd) && (e->r > 0))
	{
		if (FD_ISSET(i, &e->fd_read))
			e->fds[i].fct_read(e, i);
		if (FD_ISSET(i, &e->fd_write))
			e->fds[i].fct_write(e, i);
		if (FD_ISSET(i, &e->fd_read)
			|| FD_ISSET(i, &e->fd_write))
			e->r--;
		i++;
	}
}

void	clean_fd(int cs, t_env *e)
{
  e->fds[cs].type = FD_FREE;
  e->fds[cs].fct_read = NULL;
  e->fds[cs].fct_write = NULL;
  e->fds[cs].chan = NULL;
  e->fds[cs].logged = 0;
  e->fds[cs].away = NULL;
  ft_bzero(e->fds[cs].nickname, NICKNAME_SIZE);
  ft_bzero(e->fds[cs].buf_read, BUF_SIZE);
  ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
}

void	main_loop(t_env *e)
{
	while (1)
	{
		init_fd(e);
		e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
		check_fd(e);
	}
}
