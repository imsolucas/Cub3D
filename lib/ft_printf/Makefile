SRC		= ft_printf.c ft_printhex.c ft_putnbr.c ft_putstr.c \

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
OBJ		= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

test:
	@gcc *.c && ./a.out
	@rm -f ./a/out

.PHONY: all clean fclean re test