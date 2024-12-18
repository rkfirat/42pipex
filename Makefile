NAME            =   pipex
BONUS_NAME      =   pipex_bonus

CC              =   cc
CFLAGS          =   -Wall -Wextra -Werror -g -I libs/libft/
RM              =   rm -f

LIBFT_PATH      =   ./libs/libft/
LIBFT           =   $(LIBFT_PATH)libft.a

SRCS            =   src/pipex.c \
                    src/utils.c \
                    src/error.c

BONUS_SRCS      =   src/pipex_bonus.c \
                    src/utils_bonus.c \
                    src/error_bonus.c

OBJS            =   $(SRCS:.c=.o)
BONUS_OBJS      =   $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	
bonus: $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT)
	
$(LIBFT):
	@make -s -C $(LIBFT_PATH)
	@make -s -C $(LIBFT_PATH) clean
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus
