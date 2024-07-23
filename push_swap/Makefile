NAME 	= 	push_swap
CC		= 	cc
CFLAG		= 	-Wextra -Werror -Wall
RM		=	-rm
SRC		= 	list.c\
			init_number.c\
			init_number_utils.c\
			utils.c		\
			quick_sort.c		\
			stack_sort.c	\
			operator.c	\
			operator2.c	\
			operator3.c	\
			base_case.c	\
			base_case_utils.c\
			main.c

OBJS		=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
