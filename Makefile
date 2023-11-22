SRCS	=	ft_printf.c	\
			ft_printf_utils.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	ft_printf.h

NAME	=	libftprintf.a

CC		=	cc

AR		=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

%.o		:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

clean	:
	rm -f ${OBJS} ${B_OBJS}

fclean	:	clean
	rm -f ${NAME} ${B_OBJS}

re		:	fclean all

.PHONY	:	all clean fclean re