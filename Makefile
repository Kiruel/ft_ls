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

SOURCE = ft_ls.c \
	main.c \
	ft_addlink.c \
	ft_print_list.c \
	ft_sort_list.c \
	ft_swap_brick.c \
	ft_list_reverse.c \
	ft_align_right.c \
	ft_print_l.c \
	ft_count_space.c \
	ft_add_space_owner.c \
	ft_find_path.c \
	ft_recursive.c \
	ft_mega_join.c \
	ft_find_hidden_path.c \
	ft_return_index.c \
	ft_align_right_now.c \
	ft_print_time.c \
	ft_put_permissions.c \
	ft_print_fail.c \
	ft_find_opt.c

POINTO = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc $(CFLAG) -c $(SOURCE) 
	@gcc $(CFLAG) -o $(NAME) $(POINTO) -L libft/ -lft -I includes/
	@make clean

test:
	@gcc $(CFLAG) -c $(SOURCE) 
	@gcc $(CFLAG) -o $(NAME) $(POINTO) -L libft/ -lft -I includes/
	@make clean

clean:
	@rm -rf $(POINTO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all test fclean clean re