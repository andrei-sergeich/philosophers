NAME		=	philo_bonus

SRCS		=	${shell find ./srcs -name "*.c"}
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

HEADER		=	-I./include/philo.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS) include/philo_bonus.h
			@echo "\033[33m----Compiling project----"
			@$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME)
			@#clear
			@echo "Let's some sem, my Master!!!"

%.o:		%.c
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus