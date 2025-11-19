NAME := pipex
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := pipex.c ft_strjoin.c ft_strdup.c ft_strncmp.c ft_strchr.c ft_split.c pipex_utils.c
OBJS := $(SRCS:.c=.o)

BONUS_SRCS := pipex_bonus.c pipex_setup_bonus.c pipex_utils_bonus.c get_next_line.c get_next_line_utils.c ft_strjoin.c ft_strncmp.c ft_split.c ft_strchr.c ft_strdup.c
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)


clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
