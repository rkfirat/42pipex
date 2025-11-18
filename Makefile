NAME := pipex
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := pipex.c pipex_utils.c
OBJS := $(SRCS:.c=.o)

BONUS_SRCS := pipex_bonus.c exec_bonus.c heredoc_bonus.c utils.c
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
