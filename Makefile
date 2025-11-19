NAME := pipex
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := ft_split.c pipex_utils.c pipex.c ft_strdup.c ft_strncmp.c ft_strchr.c ft_strjoin.c
OBJS := $(SRCS:.c=.o)

BONUS_SRCS := pipex_bonus.c exec_bonus.c heredoc_bonus.c utils.c
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
