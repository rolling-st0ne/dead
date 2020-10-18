# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casteria <casteria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 23:14:28 by casteria          #+#    #+#              #
#    Updated: 2020/10/18 16:19:22 by casteria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
HEADER = philo_one.h
SRCS =	main.c errors.c utils.c init.c vicious_circle.c clean.c init_utils.c \
		output.c
OBJS = $(SRCS:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LIB = -lpthread
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re