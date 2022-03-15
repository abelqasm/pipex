SRCS = pipex.c \
	pipex_child.c \
	./srcs/ft_errors.c \
	./srcs/ft_split.c \
	./srcs/ft_strncmp.c \
	./srcs/ft_strjoin.c

OBJS = $(SRCS:.c=.o)

SRCSB = pipex_bonus.c \
	pipex_bonus_child.c \
	heredoc_bonus.c \
	./get_next_line/get_next_line_utils.c \
	./get_next_line/get_next_line.c \
	./srcs/ft_errors.c \
	./srcs/ft_split.c \
	./srcs/ft_strncmp.c \
	./srcs/ft_strcmp.c \
	./srcs/ft_strjoin.c \
	./srcs/ft_close_pipes.c

OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = pipex
BONUS = pipex_bonus
FTPRINTF=./ft_printf/libftprintf.a

all : $(NAME) 

bonus : $(BONUS)

$(NAME) : $(OBJS) ftprintf
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) -o $(NAME)

$(BONUS) : $(OBJSB) ftprintf
	$(CC) $(CFLAGS) $(OBJSB) $(FTPRINTF) -o $(BONUS)

ftprintf :
	cd ./ft_printf && make

clean :
	rm -rf *.o srcs/*.o get_next_line/*.o
	cd ./ft_printf && make clean

fclean : clean
	rm -f $(NAME) $(BONUS)
	cd ./ft_printf && make fclean

re : fclean all bonus
	cd ./ft_printf && make re
