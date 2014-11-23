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

NAME = ft_ls

CFLAG = -Wall -Werror -Wextra 

SOURCE = ft_ls.c \
	ft_ls_a.c \
	main.c \
	ft_addlink.c \
	ft_print_list.c \
	ft_sort_list.c \
	ft_swap_brick.c

POINTO = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc $(CFLAG) -c $(SOURCE) -L libft/ -lft
	@gcc -o $(NAME) $(POINTO) -L libft/ -lft -I includes/
	@make clean

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all