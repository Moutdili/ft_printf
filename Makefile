# Nom de la bibliothèque
NAME = ft_printf.a

# Fichiers sources
SRCS = ft_printf.c print_char.c print_str.c print_hex.c print_digits.c print_pointer.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règles de construction
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Suppression des fichiers objets
clean:
	rm -f $(OBJS)

# Suppression de la bibliothèque et des fichiers objets
fclean: clean
	rm -f $(NAME)

# Reconstruction de la bibliothèque
re: fclean all

.PHONY: all clean fclean re

