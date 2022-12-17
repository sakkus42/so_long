NAME = libftprintf.a

SRCS = 	ft_printf.c\
		ft_print_hex.c\
		ft_print_itoa.c\
		ft_print_unsigned.c\
		ft_ptr_adress.c\
		ft_write.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}

		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
