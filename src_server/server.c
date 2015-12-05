/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 22:34:07 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:17:01 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		fd_serv = 0;

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		close(fd_serv);
		printf("Shut down server\n");
		exit(2);
	}
}

int		main(int ac, char **av)
{
	t_env	env;
	
	if (ac != 2)
		exit_error("Usage: ./serveur <port>", -1);
	else
	{
		signal(SIGINT, sig_handler);
		init_env(&env);
		if (!ft_is_str_number(av[1]))
			exit_error("Usage: ./serveur <port>", -1);
		env.port = ft_atoi(av[1]);
		fd_serv = srv_create(&env, env.port);
		main_loop(&env);
	}
	close(fd_serv);
	return (0);
}
