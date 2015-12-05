/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:52:18 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 23:22:36 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*args_to_string_start(char **args, int start)
{
	int		i;
	char	*ret;

	i = start;
	ret = "";
	while(args[start])
	{
		ret = ft_mstrjoin(3, ret, args[start], " ");
		start++;
	}
	return (ret);
}

void	trim_end_buffer(char *str)
{
	int	i;

	i = 0;
	while (i < BUF_SIZE + 1)
	{
		if (str[i] == '\n')
			str[i] = 0;
		i++;
	}
}

void	cut_newline(t_fd *fd)
{
	char	*str;
	char	*tmp;
	int		nl;

	str = fd->buf_read;

	nl = ft_strchr(str, '\n') - str;
	tmp = ft_strsub(str, nl + 1, BUF_SIZE - nl);
	if (!tmp)
		ft_bzero(str, BUF_SIZE);
	else
		ft_strcpy(str, ft_strsub(str, nl + 1, BUF_SIZE - nl));
}

void	line_received(int cs, t_env *e)
{
	t_cmd	cmd;

	cmd.error = NULL;
	cmd = parse_buffer(e->fds[cs].buf_read);
	if (e->fds[cs].logged)
		go_to_cmd(&cmd, cs, e);
	else if (!ft_strcmp(cmd.cmd, "login"))
		cmd_login(&cmd, cs, e);
	else
		send_error(cs, "You need to login before any action\n/login username", e);
	cut_newline(&e->fds[cs]);
	if (ft_strchr(e->fds[cs].buf_read, '\n'))
		line_received(cs, e);
}
