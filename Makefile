# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/09 22:42:37 by zcarde            #+#    #+#              #
#    Updated: 2015/09/03 04:26:11 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = serveur

SRV_F = src_server

C_F = src_client

SRCC = $(C_F)/clean_fd.c\
$(C_F)/client.c\
$(C_F)/commandes.c\
$(C_F)/error.c\
$(C_F)/exit.c\
$(C_F)/inits.c\
$(C_F)/line_received.c\
$(C_F)/parsing.c\
$(C_F)/prints.c\
$(C_F)/send_command.c\
$(C_F)/server_rw.c\
$(C_F)/stdin_rw.c


SRCS = $(SRV_F)/server.c\
$(SRV_F)/client_read.c\
$(SRV_F)/client_write.c\
$(SRV_F)/cmd_away.c\
$(SRV_F)/cmd_help.c\
$(SRV_F)/cmd_invite.c\
$(SRV_F)/cmd_join.c\
$(SRV_F)/cmd_kick.c\
$(SRV_F)/cmd_leave.c\
$(SRV_F)/cmd_login.c\
$(SRV_F)/cmd_msg.c\
$(SRV_F)/cmd_nick.c\
$(SRV_F)/cmd_syn_error.c\
$(SRV_F)/cmd_time.c\
$(SRV_F)/cmd_who.c\
$(SRV_F)/commandes.c\
$(SRV_F)/debug.c\
$(SRV_F)/dest_from_name.c\
$(SRV_F)/error.c\
$(SRV_F)/inits.c\
$(SRV_F)/line_functions.c\
$(SRV_F)/main_loop.c\
$(SRV_F)/nickname.c\
$(SRV_F)/parsing.c\
$(SRV_F)/send.c

OBJC = $(SRCC:.c=.o)

OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Werror -Wextra

LIBFT = libft -lft

INCLUDES = -I libft/includes -I includes 

.PHONY: libft.a

all: libft.a $(CLIENT) $(SERVER)
	
libft.a:
	@$(MAKE) -C ./libft

$(CLIENT) : $(OBJC)
	gcc $(FLAG) $(OBJC) $(INCLUDES) -L$(LIBFT) -o $(CLIENT)

$(SERVER) : $(OBJS)
	gcc $(FLAG) $(OBJS) $(INCLUDES) -L$(LIBFT) -o $(SERVER)

%.o: %.c
	gcc $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C ./libft
	rm -f $(OBJC)
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all
