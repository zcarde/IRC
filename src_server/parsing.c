/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:53:43 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:54:00 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
		(*cmd).error = ft_strdup("Invalid command");
}

void	get_args(char *data, t_cmd *cmd)
{
	char *line;

	line = ft_strsub(data, 0, ft_strchr(data, '\n') - data);
	cmd->args = ft_strsplit_fn(line, ft_isspace);
}

t_cmd	parse_buffer(char *data)
{
	t_cmd	cmd;

	cmd.error = NULL;
	if (data[0] != '/')
		cmd.error = ft_strdup("Not a command");
	else
	{
		get_cmd(data + 1, &cmd);
		if (!cmd.error)
			get_args(data, &cmd);
	}
	return (cmd);
}
