/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_serv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 23:07:31 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:08:07 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SERV_H
# define STRUCT_SERV_H

typedef struct	s_cmd
{
	char	cmd[CMD_MAX_SIZE];
	char	**args;
	char	*error;
}				t_cmd;

typedef struct	s_fd
{
	int		type;
	char	*chan;
	char	*away;
	int		logged;
	char	nickname[NICKNAME_SIZE + 1];
	void	(*fct_read)();
	void	(*fct_write)();
	char	buf_read[BUF_SIZE + 1];
	char	buf_write[BUF_SIZE + 1];

}				t_fd;

typedef struct	s_env
{
	t_fd	*fds;
	int		port;
	int		maxfd;
	int		max;
	int		r;
	fd_set	fd_read;
	fd_set	fd_write;
}				t_env;

#endif
