#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2014/11/20 15:13:15 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls.a

CFLAG = -Wall -Werror -Wextra 

SOURCE = ft_ls.c

POINTO = ft_ls.o

all: $(NAME)

$(NAME):
	@gcc $(CFLAG) -c $(SOURCE) -I includes
	@ar rc ft_ls.a $(POINTO)
	@ranlib ft_ls.a
test:
	@gcc $(CFLAG) ft_ls.c

clean:
	@rm -rf $(POINTO)


fclean: clean
	@rm -rf $(NAME)

re: fclean all