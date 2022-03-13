SRCS = pipex.c \
	pipex_child.c \
	./srcs/ft_errors.c \
	./srcs/ft_split.c \
	./srcs/ft_strncmp.c \
	./srcs/ft_strjoin.c

OBJS = $(SRCS:.c=.o)

SRCSB = pipex_bonus.c \
	pipex_bonus_child.c \
	./srcs/ft_errors.c \
	./srcs/ft_split.c \
	./srcs/ft_strncmp.c \
	./srcs/ft_strjoin.c \
	./srcs/ft_close_pipes.c

OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = pipex
BONUS = pipex_bonus

all : $(NAME) 

bonus : $(BONUS)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS) : $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(BONUS) -fsanitize=address -g

clean :
	rm -rf *.o srcs/*.o

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all
