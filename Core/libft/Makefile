NAME = libft.a

FILENAMES = \
main.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \

CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(FILENAMES:.c=.o)

all: $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

%.o: %.c
	gcc $(CFLAGS) -O2 -c $< -o $@
