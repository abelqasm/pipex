NAME = libftprintf.a

SRCS = ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_printf.c \
		ft_print_hexa_low.c \
		ft_print_hexa_up.c \
		ft_putnbr_uns.c \
		ft_print_adress.c \
		check_print.c

OBJS = $(SRCS:.c=.o)

CC = gcc -c -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	${CC} $(SRCS) 
	ar -rc $(NAME) $(OBJS)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all