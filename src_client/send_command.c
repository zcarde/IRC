/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 22:01:34 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 22:01:46 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_cmd(t_cmd cmd, t_env *e)
{
	char	*commande;
	int		i;

	i = 0;
	commande = ft_strdup("");
	while (cmd.args[i])
	{
		if (i == 0)
			commande = ft_strjoin(commande, cmd.args[i]);
		else
			commande = ft_strjoin(ft_strjoin(commande, " "), cmd.args[i]);
		i++;
	}
	ft_strappend(e->srv.buf_write, ft_strjoin(commande, "\n"), BUF_SIZE);
}

void	send_cmd_msgc(t_cmd cmd, t_env *e)
{
	char	*commande;
	int		i;

	i = 0;
	commande = ft_strdup("/msgc ");
	while (cmd.args[i])
	{
		if (i == 0)
			commande = ft_strjoin(commande, cmd.args[i]);
		else
			commande = ft_strjoin(ft_strjoin(commande, " "), cmd.args[i]);
		i++;
	}
	ft_strappend(e->srv.buf_write, ft_strjoin(commande, "\n"), BUF_SIZE);
}
