NAME		= fdf
CC		= cc
RM		= -rm f
CFLAG		=	-g -Wall -Werror -Wall -fsanitize=address
MLX_FLAG		=	-Lminilibx-linux -lmlx -lXext -lX11 -lm
HEADER		= ./fdf.h

SRCS		=	draw.c  \
			key.c\
			main.c \
			bresenham.c \
			draw_utils.c\
			scale.c\
			map_load.c       \
			map_read.c	\
			utils.c		\
			isometric.c	\
			map_load_utils.c\
			color.c\

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./minilibx-linux
	$(CC) $(CFLAG) -o $@ $^ $(MLX_FLAG)

clean :
	@make clean -C ./minilibx-linux
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
