NAME	= philo
CC		= cc
CFLAG	= -g  #-Wextra -Werror -Wall

SRCS	= main.c\
		  utils.c

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re