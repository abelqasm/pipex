SRCS = pipex.c \
	pipex_child.c \
	./srcs/ft_errors.c \
	./srcs/ft_split.c \
	./srcs/ft_strncmp.c \
	./srcs/ft_strjoin.c

OBJS = $(SRCS:.c=.o)

CC=cc
CFLAGS=-Werror -Wextra -Wall
NAME=pipex

all : $(NAME) 

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o srcs/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all
