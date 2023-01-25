
NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
SRC = so_long.c ft_putstr.c ft_putnbr.c ft_printf.c ft_strnstr.c data_checker.c \
ft_putnbrhex.c ft_argprint.c get_next_line.c get_next_line_utils.c ft_substr.c map_checker.c ft_strncmp.c \
moves_checker.c move_keys.c infect_bis.c 
SRC_BONUS = so_long_bonus.c ft_putstr.c ft_putnbr.c ft_printf.c ft_strnstr.c ft_putnbrhex.c ft_argprint.c \
get_next_line.c get_next_line_utils.c ft_substr.c data_checker_bonus.c map_checker_bonus.c ft_strncmp.c \
moves_checker_bonus.c move_keys_bonus.c infect_bis_bonus.c frame_utils_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo ---program linked---

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo ---BONUS program linked---

clean:	
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo ---objects cleaned---

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo ---program cleaned---

re: fclean all

.PHONY: all clean fclean re
