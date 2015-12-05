/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:59:40 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/03 01:13:52 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	print_msg(char *msg)
{
	ft_putstr("\033[0m");
	ft_putstr(msg);
	ft_putendl("\033[0m");
}

void	print_error(char *error)
{
	ft_putstr("\033[31m");
	ft_putstr(error);
	ft_putendl("\033[0m");
}

void	print_info(char *info)
{
	ft_putstr("\033[32m");
	ft_putstr(info);
	ft_putendl("\033[0m");
}
