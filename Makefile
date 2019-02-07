# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thorker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:25:57 by thorker           #+#    #+#              #
#    Updated: 2019/01/22 17:53:09 by thorker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -Wall -Wextra -Werror
SRC = main.c move.c sub_coor.c get_coor.c put_line.c brigh.c put_map.c
INC = -I /usr/local/include -I libft/
LIB = -L /usr/local/lib -lmlx -L libft/ -lft
FRWR = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(INC) $(LIB) $(SRC) -o $(NAME) $(FRWR)

clean:
	make -C libft/ clean
	rm -rf *.o

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

git: clean
	git add --all
	git status
	git commit -m "auto git"
	git push
