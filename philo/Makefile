# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:11:02 by anachat           #+#    #+#              #
#    Updated: 2025/06/27 15:43:55 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   philo

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror #-fsanitize=thread -g3

SRCS        =   philo.c utils.c parse.c init.c helpers.c dinner.c \
				monitor.c dinner_actions.c
OBJS        =   $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all