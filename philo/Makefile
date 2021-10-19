NAME		=	philo

SRCS_FILES	=	${shell find ./srcs -name "*.c"}

SRCS		=	$(SRCS_FILES) # remove!!!!!!!!!!!!!!!!!!!!
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

HEADER		=	-I./include/philo.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS_MAN) include/philo.h
			@echo "\033[33m----Compiling project----"
			@$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME)
			@#clear
			@echo "Let's some mute, my Master!!!"

%.o:		%.c
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus