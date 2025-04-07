# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:11:02 by anachat           #+#    #+#              #
#    Updated: 2025/04/07 14:51:51 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   philo

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

SRCS        =   philo.c utils.c parse.c init.c helpers.c dinner.c
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