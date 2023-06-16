# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:18:12 by adi-stef          #+#    #+#              #
#    Updated: 2023/06/12 17:41:47 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN

SRC		= main.cpp
OBJ		= $(SRC:%.cpp=%.o)

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -f

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
