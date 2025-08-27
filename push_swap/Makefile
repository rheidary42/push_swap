NAME := push_swap
HEADER := push_swap.h
CC := @cc
CFLAGS := -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

SRC = push_swap.c\
	init_structs.c\
	input_parsing.c\

OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS) $(HEADER)
	@cc $(SRC) $(LIBFT) $(FT_PRINTF) -o $(NAME) $(CFLAGS)
	@echo "Executable created"

# --- libraries ---

$(LIBFT):
	@make -sC libft

$(FT_PRINTF):
	@make -sC ft_printf

# --- cleaning ---

clean:
	@rm -f $(OBJS)
	@make clean -sC libft
	@make clean -sC ft_printf
	@echo "Objects removed\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC libft
	@make fclean -sC ft_printf
	@echo "Executable removed\n"

re: fclean all

.PHONY: all clean fclean re