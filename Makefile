# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 15:29:01 by akorol            #+#    #+#              #
#    Updated: 2019/05/30 15:29:04 by akorol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = akorol.filler

SRC =   main.c	\
        file1.c \
        file2.c \
        file3.c \

CFLAGS = -Wextra -Wall -Werror

LIB = libft/libft.a

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):$(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LIB)

$(OBJ):%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

$(LIB):
	make -C libft/

clean:
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all