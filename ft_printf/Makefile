NAME		= libftprintf.a
CC		= cc
CFLAG		= -Wall -Wextra -Werror
RM		= rm -f
AR		= ar
ARFLAGS		= crs
HEADER		= ./ft_printf.h

SRC		= ft_printf.c \
		  printchar.c  \
		  printhex.c    \
		  printstring.c  \
		  printinteger.c  \
		  printinteger.c   \
		  printpointer.c

OBJS		= $(SRC:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re

