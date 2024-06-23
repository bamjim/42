Name 	= 	push_swap
CC		= 	cc
CFLAG	= 	-Wextra -Werror -Wall
RM		=	-rm f
SRC		= 	deque.c\
			init_number.c\
			init_number_utils.c\
			main.c\

OBJS		=	$(SRC: .c = .o)

all : $(Name)

$(Name) : $(OBJS)
	$(CC) $(CFLAG) -o -$@ $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(Name)

re : fclean all

.PHONY : all clean fclean re
