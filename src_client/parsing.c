/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:00:49 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:00:25 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	get_cmd(char *str, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\n' && i < CMD_MAX_SIZE)
	{
		(*cmd).cmd[i] = str[i];
		i++;
	}
	(*cmd).cmd[i] = 0;
	if (!is_valid_cmd((*cmd).cmd))
		(*cmd).cmd[0] = 0;
}

void	get_args(char *data, t_cmd *cmd)
{
	cmd->args = ft_strsplit_fn(data, &ft_isspace);
}

t_cmd	parse_line(char *data)
{
	t_cmd	cmd;

	cmd.error = NULL;
	if (data[0] == '\n')
		return (cmd);
	else if (data[0] != '/')
		ft_strcpy(cmd.cmd, "msgc");
	else
		get_cmd(data + 1, &cmd);
	if (!cmd.error && cmd.cmd)
		get_args(data, &cmd);
	return (cmd);
}
