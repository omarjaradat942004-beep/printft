NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_itoa.c \
	ft_printf.c \
	ft_printf_char.c \
	ft_printf_decimal.c \
	ft_printf_lower.c \
	ft_printf_ptr.c \
	ft_printf_str.c \
	ft_printf_unint.c \
	ft_printf_upper.c






OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
