# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 20:45:05 by mpazouki          #+#    #+#              #
#    Updated: 2025/09/01 20:45:06 by mpazouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Account

SRCS = Account.cpp\
		tests.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean: 
	@$(RM)  $(OBJS)
fclean: clean
	@$(RM)  $(NAME)

re: fclean all

.PHONY: all clean fclean re
	