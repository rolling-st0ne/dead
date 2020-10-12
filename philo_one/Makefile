# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casteria <mskoromec@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 23:14:28 by casteria          #+#    #+#              #
#    Updated: 2020/10/12 03:32:36 by casteria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
HEADER = philo_one.h
SRCS = main.c errors.c utils.c init.c ,philo.c process.c print.c clean.c utils.c
OBJS = $(SRCS:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
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