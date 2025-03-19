# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:11:02 by anachat           #+#    #+#              #
#    Updated: 2025/03/19 14:35:21 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS  =   philo_bonus

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

SRCS_BONUS  =   philo_bonus.c utils_bonus.c
OBJS_BONUS  =   $(SRCS_BONUS:.c=.o)

all: $(NAME_BONUS)

%_bonus.o: %_bonus.c philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME_BONUS)

re: fclean all