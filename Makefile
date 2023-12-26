# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:13:37 by kyacini           #+#    #+#              #
#    Updated: 2023/12/23 01:26:25 by kyacini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/main.c \
		src/parsing.c \
		src/utils.c \
		src/error.c \
		src/norm.c \
		src/loader.c \
		src/raycasting.c \
		src/image.c \
		src/initialisation.c \
		src/moves_handler.c \
		src/destroyer.c \
		src/moves.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJS =	objs/main.o \
		objs/utils.o\
		objs/error.o\
		objs/norm.o\
		objs/loader.o\
		objs/raycasting.o \
		objs/image.o \
		objs/initialisation.o\
		objs/moves_handler.o\
		objs/destroyer.o\
		objs/moves.o\
		objs/parsing.o\
		gnl/get_next_line.o\
		gnl/get_next_line_utils.o\

NAME = cub3D

CC = gcc

INC = include/

RM = rm -rf

CFLAGS = -Wall  -Wextra

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFLAGS = -L libft -lft

all : ${NAME}

objs/%.o : src/%.c
	mkdir -p ./objs
	$(CC)  -I${INC} -c $< -o $@ ${CFLAGS}

%.o : %.c
	$(CC)  -I${INC} -c $< -o $@ ${CFLAGS} 

${NAME} : ${OBJS} $(LIB)
	make -C ./libft
	make -C ./mlx_linux
	$(CC) ${OBJS} -D LINUX ${MLXFLAGS} ${LIBFLAGS} -o ${NAME} ${CFLAGS}

clean:
		$(RM) ${OBJS} $(OBJ_B)
		$(RM) ./objs
		make clean -C ./mlx_linux
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		$(RM) ./mlx_linux/libmlx_Linux.a
		$(RM) ./mlx_linux/libmlx.a
		$(RM) ./libft/libft.a

re:	fclean all

.PHONY:        all clean fclean re