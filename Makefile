# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaragi <afaragi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 00:15:01 by afaragi           #+#    #+#              #
#    Updated: 2019/12/23 00:30:41 by afaragi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=main.c \
srcs/ft_colors.c \
srcs/ft_ex_finder.c \
srcs/ft_link_printer.c \
srcs/ft_linkdir.c \
srcs/ft_ls.c \
srcs/ft_read_list_add.c \
srcs/ft_sort_tab_time.c \
srcs/ft_strjoinfirst.c \
srcs/is_directory.c \
srcs/option.c \
srcs/other_print_tools.c \
srcs/print_mode.c \
srcs/print_tools.c \
srcs/read_file.c \
srcs/rec_flagr.c \
srcs/rev_tab.c \
srcs/sort_list.c \
srcs/st_ftr_mod.c \
srcs/swap_tools.c \

NAME = ft_ls

LIB = -Llibft -lft

HEADERS = ft_ls.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc -o $(NAME) $(OBJ) $(LIB) -I $(HEADERS)

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<