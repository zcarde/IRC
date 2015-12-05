/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_rw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:06:38 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:31:21 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		stdin_read(t_env *e)
{
	char	buff[BUF_SIZE];
	int		ret;

	ret = read(STDIN, buff, BUF_SIZE + 1);
	if (ret >= 0)
	buff[ret] = 0;
	if (buff[0] == 10)
		print_info("/quit for close program");
	else
	{
		ft_strappend(e->stdin.buf_read, buff, BUF_SIZE);
		if (ft_strchr(e->stdin.buf_read, '\n'))
			line_received(e);
	}

}

static char	*get_line(char *str)
{
	char	*ret;
	int		nl;
	int		i;

	i = 0;
	nl = ft_strchr(str, '\n') - str;
	if (nl <= 0)
		return (str);
	ret = (char *)malloc(sizeof(char) * (nl + 1));
	while (str[i] && i < nl)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void		stdin_write(t_env *e)
{
	int		nl;

	nl = ft_strchr(e->stdin.buf_write, '\n') - e->stdin.buf_write;
	if (nl > 0)
	{
		ft_putendl(get_line(e->stdin.buf_write));
		ft_putendl_fd(get_line(e->stdin.buf_write), e->logfd);
		cut_newline(&e->stdin, 0);
		if (ft_strchr(e->stdin.buf_write, '\n'))
			stdin_write(e);
	}
}
