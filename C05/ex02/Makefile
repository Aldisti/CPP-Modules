# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:18:12 by adi-stef          #+#    #+#              #
#    Updated: 2023/05/20 17:49:03 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= no_you_need_form_28b_not_28c

SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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
