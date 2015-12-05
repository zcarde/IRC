/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:08:31 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:08:42 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	clean_fd(t_fd *fd, int srv)
{
  fd->type = FD_FREE;
  if (srv)
  	fd->fct_read = server_read;
  else
  	fd->fct_read = stdin_read;
  if (srv)
  	fd->fct_write = server_write;
  else
  	fd->fct_write = stdin_write;
  fd->chan = NULL;
  ft_bzero(fd->buf_read, BUF_SIZE);
  ft_bzero(fd->buf_write, BUF_SIZE);
}
