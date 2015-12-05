/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/02 21:46:48 by zcarde            #+#    #+#             */
/*   Updated: 2015/09/02 21:46:56 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cmd_help(int fd, t_env *e)
{
	send_message(fd, "Commands for NeoIRC:", e);
	send_message(fd, "\t- /nick nickname (Change your nickname)", e);
	send_message(fd, "\t- /join #channel (Join a channel)", e);
	send_message(fd, "\t- /leave (Leave a channel)", e);
	send_message(fd, "\t- /who (List users in your channel", e);
	send_message(fd, "\t- /msg nickname message (Send a private message)", e);
	send_message(fd, "\t- /msgc <message> (Send message to your channel)", e);
	send_message(fd, "\t- /invite nickname (Invite user to channel)", e);
	send_message(fd, "\t- /time (Display date)", e);
	send_message(fd, "\t- /away [message] (Automatic response from private messages)", e);
	send_message(fd, "\t- /kick nickname [message] (Kick user from your channel)", e);
}
