# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 02:35:06 by sid-bell          #+#    #+#              #
#    Updated: 2018/12/10 03:10:06 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
all : $(NAME)
$(NAME) :
	clang -Wall -Wextra -Werror -c *.c libft/*.c
	ar rc $(NAME) *.o
clean :
	rm -rf *.o
	rm -rf libft/*.o
fclean : clean
	rm -rf  $(NAME)
re :fclean all
