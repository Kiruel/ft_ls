make -C libft/ fclean
make -C libft
make -C libft/ clean
gcc -Wall -Wextra -Werror -I libft/includes/ -c ft_ls.c
gcc -o ft_ls ft_ls.o -L libft/ -lft
rm -rf *.o