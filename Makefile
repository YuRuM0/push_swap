NAME = push_swap

SRCS = errors.c low_sort_utils.c low_sort.c main.c push.c radix_sort.c rotate.c\
			stack_init.c swap.c utils.c more_errors.c

LIBFT = libft_combined/libft.a

OBJECTS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
R = ar rsc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C libft_combined

clean:
	$(MAKE) -C libft_combined clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C libft_combined fclean
	$(RM) $(NAME)

re: fclean all
