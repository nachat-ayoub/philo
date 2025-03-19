# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anachat <anachat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:11:02 by anachat           #+#    #+#              #
#    Updated: 2025/03/18 17:57:58 by anachat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        =   philo
NAME_BONUS  =   philo_bonus

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror


MANDATORY   =   philo
BONUS       =   philo_bonus

SRCS        =   $(MANDATORY)/philo.c $(MANDATORY)/utils.c

SRCS_BONUS  =   $(BONUS)/philo_bonus.c $(BONUS)/utils_bonus.c

OBJS        =   $(SRCS:.c=.o)
OBJS_BONUS  =   $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(MANDATORY)/%.o: $(MANDATORY)/%.c $(MANDATORY)/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS)/%_bonus.o: $(BONUS)/%_bonus.c $(BONUS)/philo_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: $(MANDATORY) $(BONUS)