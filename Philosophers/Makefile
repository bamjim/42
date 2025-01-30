NAME	= philo
CC		= cc
CFLAG	=  -Wextra -Werror -Wall

SRCS	= 	main.c\
			init.c\
			utils.c\
			main_thread.c\
			philo_thread.c\
			philo_thread2.c\
			shared_resource.c

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
