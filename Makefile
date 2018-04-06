NAME = push_swap
CHECKER = checker

FILES = srcs/sorting_methods.c \
		srcs/stack.c \
		srcs/stack_commands.c \
		srcs/stack_commands2.c \
		srcs/utils.c \
		srcs/checker_dispatch.c \
		srcs/get_next_line.c
		
CHECKER_FILES = src/checker.c
OBJECTS = $(FILES:srcs/%.c=%.o)
HDR = includes/
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re checker

all: $(NAME) $(CHECKER)

$(NAME): $(LIBFT)
	gcc -c $(FLAGS) main.c $(FILES) -I$(HDR) -I./libft
	gcc -o $(NAME) $(FLAGS) $(OBJECTS) $(LIBFT) main.o -I./libft -I$(HDR)

$(CHECKER):
	gcc -c $(FLAGS) srcs/checker.c $(FILES) -I$(HDR) -I./libft
	gcc -o $(CHECKER) $(FLAGS) $(OBJECTS) $(LIBFT) checker.o -I./libft -I$(HDR)

$(LIBFT):
	make -C ./libft

clean:
	@make clean -C ./libft
	@/bin/rm -f $(OBJECTS) main.o checker.o

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(CHECKER)

re: fclean all

check: $(LIBFT)
	gcc -c srcs/checker.c $(FILES) -I$(HDR) -I./libft
	gcc -o $(CHECKER) $(OBJECTS) $(LIBFT) checker.o -I./libft -I$(HDR)