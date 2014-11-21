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
	main.c

POINTO = ft_ls.o \
	ft_ls_a.o \
	main.o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft
	@make -C libft/ clean
	@gcc $(CFLAG) -L libft/includes/ -lft -c $(SOURCE)
	@gcc -o $(NAME) $(POINTO) -L libft/ -lft
	@ar rc ft_ls_a $(POINTO)
	@ranlib ft_ls.a
test:
	@gcc $(CFLAG) -o ft_ls $(NAME)

clean:
	@rm -rf $(POINTO)


fclean: clean
	@rm -rf $(NAME)

re: fclean all