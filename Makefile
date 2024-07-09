# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 14:28:44 by mamichal          #+#    #+#              #
#    Updated: 2024/07/09 14:32:37 by mamichal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -fr
INCLUDES = ./includes/fractol.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = ./mlx_linux
MLX = $(MLX_PATH)/libmlx_Linux.a

SRCS = src/fractal_render.c \
		src/fractol_data_init.c \
		src/ft_atod.c \
		src/handle_events.c \
		src/main.c \
		src/math_utils.c \
		src/my_pixel_put.c


OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -include $(INCLUDES)

${NAME}: $(OBJS) ${LIBFT} $(MLXLIB)
	${CC} ${FLAGS} $(MLXFLAGS) -o ${NAME} $(OBJS) ${LIBFT} $(MLX) -include $(INCLUDES)
	echo Compiling Base Executable

all: ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all

$(MLXLIB):
	make -C $(MLX_PATH) all

clean:
	${RM} *.o */*.o */*/*.o
	${RM} $(ARCH)
	make -C ${LIBFT_PATH} fclean
	echo Only Exec Left

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	echo All Clear

re: fclean all

.SILENT:

.PHONY: all clean fclean re
