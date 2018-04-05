NAME = push_swap
CHECKER = checker

FILES = src/sorting_methods.c \
		src/stack.c \
		src/stack_commands.c \
		src/stack_commands2.c \
		src/utils.c
		
CHECKER_FILES = src/checker.c
OBJECTS = $(FILES:%.c=%.o)
HDR = includes/stack.h
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -c $(FLAGS) main.c $(FILES) -I$(INCLUDES) -I./libft
	@gcc -o $(NAME) $(FLAGS) $(OBJECTS) $(LIBFT) main.o -I./libft -I$(HDR)

$(LIBFT):
	@make -C ./libft

clean:
	@make clean -C ./libft
	@/bin/rm -f $(OBJECTS) main.o

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all