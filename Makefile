NAME = so_long

CC = gcc -Wall -Wextra -Werror

FILE = make_map.c \
		so_long.c \
		error.c \
		make_struct.c \
		print_map.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c

FILE_B = ./bonus/make_map_bonus.c \
		./bonus/so_long_bonus.c \
		./bonus/error_bonus.c \
		./bonus/error_bonus_2.c \
		./bonus/make_struct_bonus.c \
		./bonus/slime_bonus.c \
		./bonus/print_map_bonus.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c

OBJS = $(FILE:.c=.o)

OBJS_B = $(FILE_B:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS_B)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./mlx all
	$(CC) -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit $(OBJECTS) -o $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

bonus : $(OBJS_B)
	make WITH_BONUS=1 all

clean :
	rm -rf $(OBJS)
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./mlx clean
	rm -rf $(OBJS_B)

fclean : clean
	rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean

re : fclean all

.PHONY : all clean fclean bonus re