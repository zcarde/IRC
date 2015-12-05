/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 20:24:05 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:17:13 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_env(t_env *e)
{
	int				i;
	struct rlimit	rlp;

	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
		exit_error("Error getting maximum number of openned files", -1);
	e->maxfd = rlp.rlim_cur;
	if (!(e->fds = (t_fd *)malloc(sizeof(t_fd) * e->maxfd))) 
		exit_error("Error malloc", -1);
	i = 0;
	while (i < e->maxfd)
	{
	  clean_fd(i, e);
	  i++;
	}
}

void	init_fd(t_env *e)
{
	int	i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (i < e->maxfd)
	{
		if (e->fds[i].type != FD_FREE)
		{
			FD_SET(i, &e->fd_read);
			if (ft_strlen(e->fds[i].buf_write) > 0)
				FD_SET(i, &e->fd_write);
			e->max = MAX(e->max, i);
		}
		i++;
	}
}

void	srv_accept(t_env *e, int s)

{
	int			cs;
	struct sockaddr_in	csin;
	socklen_t		csin_len;

	csin_len = sizeof(csin);
	if ((cs = accept(s, (struct sockaddr*)&csin, &csin_len)) == -1)
		exit_error("Error accepting new client", -1);
	printf("New client #%d from %s:%d\n", cs,
	 inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	clean_fd(cs, e);
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
	send_message(cs, "Welcome to NeoIRC", e);
}

int		srv_create(t_env *e, int port)
{
	int			s;
	struct sockaddr_in	sin;
	struct protoent	*pe;

	if (!(pe = getprotobyname("tcp")))
		exit_error("Error: Can't get protocol tcp", -1);
	if (!(s = socket(PF_INET, SOCK_STREAM, pe->p_proto)))
		exit_error("Error: Can't get socket", -1);
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &s, sizeof(int)) == -1)
		exit_error("Error: Can't set socket options", -1);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
		exit_error("Error: bind", -1);
	if (listen(s, 42) == -1)
		exit_error("Error: listen", -1);
	e->fds[s].type = FD_SERV;
	e->fds[s].fct_read = srv_accept;
	return (s);
}
