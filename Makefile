#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etheodor <etheodor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 15:13:13 by etheodor          #+#    #+#              #
#    Updated: 2014/11/24 16:30:50 by etheodor         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

CFLAG = -Wall -Werror -Wextra 

SOURCE = ft_ls.c \
	main.c \
	ft_addlink.c \
	ft_print_list.c \
	ft_sort_list.c \
	ft_swap_brick.c \
	ft_list_reverse.c \
	ft_align_right.c \
	ft_print_l.c \
	ft_put_permissions.c

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
	@gcc -o $(NAME) $(POINTO) -L libft/ -lft -I includes/
	@make clean

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
