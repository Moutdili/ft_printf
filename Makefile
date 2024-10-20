# Nom de la bibliothèque
NAME = libftprintf.a

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources
SRCS = ft_printf.c \
       print_format.c \
       print_format2.c \
       handle_format.c \
       process_char.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Commande pour créer la bibliothèque
AR = ar rcs

# Compilation de la bibliothèque
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Supprime les fichiers objets
clean:
	rm -f $(OBJS)

# Supprime les fichiers objets et la bibliothèque
fclean: clean
	rm -f $(NAME)

# Recompile tout
re: fclean all

# Règle pour compiler les .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Indique que les règles ne sont pas des fichiers.
.PHONY: all clean fclean re


