NAME		= fdf.a
FDF		= c.a
CC		= cc
CFLAG		=	-Wall -Werror -Wall -lm
MLX_FLAG		=	-Lminilibx-linux -lmlx -lXext -lX11
RM		= rm -f
AR		= ar
ARFLAGS		= crs
HEADER		= ./fdf.h
SRCS		=	main.c \
			bresenham.c \
			draw.c  \
			scale.c\
			map_load.c       \
			map_read.c	\
			utils.c		\
			isometric.c	\
			map_load_utils.c\
			key.c\

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS) $(FDF)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(FDF)
	$(CC) $(CFLAG) $^ $(MLX_FLAG)

$(FDF) : $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re
