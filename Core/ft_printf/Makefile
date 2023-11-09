NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc

AR = ar rcs
RM = rm -rf

FILES = \
ft_printf.c \
ft_print_types.c \

OBJECTS = $(FILES:.c=.o)



all: 	$(NAME)


clean:
		make -C $(LIBFT_PATH) clean
		$(RM) $(OBJECTS)

fclean:		clean
		make -C $(LIBFT_PATH) fclean
		$(RM) $(NAME)

re:			fclean all

$(NAME):	$(LIBFT) $(OBJECTS)
		cp	$(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJECTS)

$(LIBFT):
		make -C $(LIBFT_PATH)
		make -C $(LIBFT_PATH) clean

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@
