/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:40:56 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:41:44 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	fill_jours_tab(char	*jours[7])
{
	jours[0] = ft_strdup("Dimanche");
	jours[1] = ft_strdup("Lundi");
	jours[2] = ft_strdup("Mardi");
	jours[3] = ft_strdup("Mercredi");
	jours[4] = ft_strdup("Jeudi");
	jours[5] = ft_strdup("Vendredi");
	jours[6] = ft_strdup("Samedi");
}

static void	fill_mois_tab(char	*mois[12])
{
	mois[0] = ft_strdup("janvier");
	mois[1] = ft_strdup("fevrier");
	mois[2] = ft_strdup("mars");
	mois[3] = ft_strdup("avril");
	mois[4] = ft_strdup("mai");
	mois[5] = ft_strdup("juin");
	mois[6] = ft_strdup("juillet");
	mois[7] = ft_strdup("aout");
	mois[8] = ft_strdup("septembre");
	mois[9] = ft_strdup("octobre");
	mois[10] = ft_strdup("novembre");
	mois[11] = ft_strdup("decembre");
}

static char	*get_str_from_time(struct tm *t)
{
	char		*jours[7];
	char		*mois[12];
	char		*ret;

	fill_jours_tab(jours);
	fill_mois_tab(mois);
	ret = jours[t->tm_wday];
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, ft_itoa(t->tm_mday));
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, mois[t->tm_mon]);
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, ft_itoa(1900 + t->tm_year));
	ret = ft_strjoin(ret, " ");
	ret = ft_strjoin(ret, ft_itoa(t->tm_hour));
	ret = ft_strjoin(ret, ":");
	ret = ft_strjoin(ret, ft_itoa(t->tm_min));
	ret = ft_strjoin(ret, ":");
	ret = ft_strjoin(ret, ft_itoa(t->tm_sec));
	ret = ft_strjoin(ret, " ");
	return (ret);
}

void		cmd_time(int fd, t_env *e)
{

	time_t		timestamp;
	struct tm 	*t;

	timestamp = time(NULL); 
	t = localtime(&timestamp);
	send_privmessage(fd, get_str_from_time(t), e);
}
