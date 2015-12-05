/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 22:24:59 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:32:51 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	main_loop(t_env *e)
{
	int		ret;

	init_fd(e);
	ret = select(e->server.socket + 1, &e->fd_read, &e->fd_write, NULL, NULL);
	if (FD_ISSET(STDIN, &e->fd_read))
		e->stdin.fct_read(e);
	else if (FD_ISSET(e->server.socket, &e->fd_read))
		e->srv.fct_read(e);
	else if (FD_ISSET(STDIN, &e->fd_write))
		e->stdin.fct_write(e);
	else if (FD_ISSET(e->server.socket, &e->fd_write))
		e->srv.fct_write(e);
}

int		main(int ac, char **av)
{
	t_env	env;
	t_cmd	cmd;

	if (ac > 3)
		exit_error("Usage: ./client [machine [port]]", -1);
	else
	{
		cmd.error = NULL;
		clean_fd(&env.srv, 1);
		clean_fd(&env.stdin, 0);
		if (ac == 3)
		{
			cmd = parse_line(ft_mstrjoin(4, "/connect ", av[1], " ", av[2]));
			init_server(&cmd, &env);
		}
		while (1)
			main_loop(&env);
	}
	close(env.server.socket);
	close(env.logfd);
	return (0);
}
