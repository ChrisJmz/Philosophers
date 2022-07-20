NAME = philo

SRCS =	srcs/main.c			\
		srcs/utils.c		\
		srcs/init.c			\
		srcs/check_args.c	\
		srcs/time.c			\
		srcs/print_msg.c	\
		srcs/status.c		\
		srcs/execute.c		\

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
INC = -I./include
RM = rm -rf

.c.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	clean all

.PHONY: all clean fclean re
