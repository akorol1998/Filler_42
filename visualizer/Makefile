# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 16:20:27 by akorol            #+#    #+#              #
#    Updated: 2019/05/30 17:04:31 by akorol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vis.filler

SRC =   visual.c  \
        v_file1.c \

CFLAGS = -Wextra -Wall -Werror

LIB = ../libft/libft.a

INC = visual.h

LIBMLX = libmlx.a

FRAME = -lmlx -framework OpenGl -framework AppKit

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LIBMLX) $(FRAME) $(LIB)

$(OBJ):%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

$(LIB):
	make -C ../libft

clean:
	make clean -C ../libft
	rm -f *.o

fclean: clean
	make fclean -C ../libft
	rm -f $(NAME)

re: fclean all
