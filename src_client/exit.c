/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:31:28 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:31:46 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	exit_properly(t_env *e)
{ 
	close(e->server.socket);
	e->server.socket = 0;
	print_info("Closing connection...\nClient exited");
	exit(0);
}
