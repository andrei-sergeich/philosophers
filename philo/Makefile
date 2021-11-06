NAME	=	philo

SRCS	=	${shell find ./srcs -name "*.c"}
OBJS	=	$(patsubst %.c,%.o,$(SRCS))
HEADER	=	./include/philo.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			@echo "\033[33m----Compiling project----"
			@$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME) -pthread
			@#clear
			@echo "Let's some mute, my Master!!!"

%.o:		%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus