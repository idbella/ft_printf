# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 03:14:42 by sid-bell          #+#    #+#              #
#    Updated: 2018/11/28 07:52:24 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=libftprintf.a
all : $(NAME)

$(NAME) :
	mv main.c main
	clang -Wall -Wextra -Werror -c *.c
	ar rc $(NAME) *.o
	mv main main.c
clean :
	rm -rf *.o
fclean : clean
	rm -rf  $(NAME)
re :fclean all
main :
	@gcc main.c $(NAME)
