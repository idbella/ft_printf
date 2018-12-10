# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 16:23:12 by sid-bell          #+#    #+#              #
#    Updated: 2018/12/09 07:03:57 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
all : $(NAME)
$(NAME) :
	@gcc -c *.c -Wall -Wextra -Werror
	ar rc $(NAME) *.o
clean :
	@rm -rf *.o
fclean : clean
	@rm -rf $(NAME)
re : fclean all
