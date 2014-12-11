#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2014/12/08 13:21:16 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CFLAG = -Wall -Werror -Wextra 

SOURCE = main.c \
	ft_find_opt.c

POINTO = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc -c $(SOURCE) 
	@gcc -o $(NAME) $(POINTO) -L libft/ -lft -I includes/
	@make clean

test:
	@gcc -c $(SOURCE) 
	@gcc -o $(NAME) $(POINTO) $(CFLAG) -g -L libft/ -lft -I includes/
	@make clean

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all test fclean clean re $(NAME)