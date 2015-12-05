/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_syn_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:47:04 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:06:18 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_syntax_error(char *error, int fd, t_env *e)
{
	if (ft_strcmp(e->fds[fd].buf_read, ""))
		send_error(fd, ft_mstrjoin(3, "Syntax error: " , error
			, "\n/help for list of commands"), e);
}
