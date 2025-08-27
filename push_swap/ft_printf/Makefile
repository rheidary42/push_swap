NAME := libftprintf.a
HEADER := libftprintf.h
CC := @cc
CFLAGS := -Wall -Wextra -Werror -g
SRC := ft_printf.c\
	utils.c\
	mem_to_str.c\

OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)
	@echo "ft_printf created"

clean:
	@rm -f $(OBJS)
	@echo "ft_printf objs removed"

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@echo "libftprintf.a removed"

re: fclean all

.PHONY: all clean fclean re