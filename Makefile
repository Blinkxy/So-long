
NAME = So_long
LIB = lib.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
AR = ar rcs
SRC = So_Long.c ft_split.c ft_itoa.c ft_putstr.c ft_putnbr.c ft_printf.c ft_strnstr.c data_checker.c \
ft_putnbrhex.c ft_argprint.c get_next_line.c get_next_line_utils.c ft_substr.c map_checker.c ft_strncmp.c \
moves_checker.c move_keys.c

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIB)	

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo ---program linked---

$(LIB): $(OBJ)
	@$(AR) $(LIB) $(OBJ)
	@echo ---library generated---

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:	
	@$(RM) $(OBJ)
	@echo ---objects cleaned---

fclean: clean
	@$(RM) $(NAME) $(LIB)
	@echo ---program cleaned---
	@echo ---library cleaned---

re: fclean all

.PHONY: all clean fclean re
