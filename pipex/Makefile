NAME		= 	pipex
CC		=	cc
CFLAG		=	 -Werror -Wextra -Wall
RM		=	rm -f 
SRC		=	ft_split.c\
			utils.c\
			pipex.c\
			pipex_utils.c

OBJ		=	$(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
