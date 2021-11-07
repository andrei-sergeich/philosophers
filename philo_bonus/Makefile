NAME	=	philo_bonus

SRCS	=	${shell find ./srcs -name "*.c"}

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

HEADER	=	./include/philo_bonus.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I. -pthread
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\033[33m----Compiling project----"
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@#clear
			@echo "Let's some sem, my Master!!!"

%.o:		%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus