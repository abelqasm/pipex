SRCS = ./Mandatory/pipex.c \
	./Mandatory/pipex_child.c \
	./utils/ft_errors.c \
	./utils/ft_split.c \
	./utils/ft_strncmp.c \
	./utils/ft_strjoin.c

OBJS = $(SRCS:.c=.o)

SRCSB = ./Bonus/pipex_bonus.c \
	./Bonus/pipex_bonus_child.c \
	./Bonus/heredoc_bonus.c \
	./get_next_line/get_next_line_utils.c \
	./get_next_line/get_next_line.c \
	./utils/ft_errors.c \
	./utils/ft_split.c \
	./utils/ft_strncmp.c \
	./utils/ft_strcmp.c \
	./utils/ft_strjoin.c \
	./utils/ft_close_pipes.c

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
	rm -rf Mandatory/*.o Bonus/*.o utils/*.o get_next_line/*.o
	cd ./ft_printf && make clean

fclean : clean
	rm -f $(NAME) $(BONUS)
	cd ./ft_printf && make fclean

re : fclean all bonus
	cd ./ft_printf && make re
