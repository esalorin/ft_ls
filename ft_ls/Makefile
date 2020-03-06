# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 14:11:59 by esalorin          #+#    #+#              #
#    Updated: 2020/02/17 14:16:08 by esalorin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = srcs/main.c srcs/ft_mode.c srcs/ft_date.c srcs/ft_ids.c srcs/ft_read_dir.c \
srcs/ft_inspect_file.c srcs/printing.c srcs/sorting.c srcs/helpers.c srcs/parameters.c \
srcs/sorting_params.c srcs/deleting.c srcs/error.c

OBJ = main.o ft_mode.o ft_date.o ft_ids.o ft_read_dir.o deleting.o error.o \
ft_inspect_file.o printing.o sorting.o helpers.o parameters.o sorting_params.o \

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	@make -C libft/
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) libft/libft.a

clean :
	@rm -f $(OBJ)
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all
