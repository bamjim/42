NAME	= philo
CC		= cc
CFLAG	= -g

SRCS	= main.c\
		  thread.c\
		  thread_philo.c\
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
