NAME =	so_long
CFLAGS =	-Wall -Werror -Wextra -g#-fsanitize=address -g3
MLXFLAGS =	-L mlx -lmlx -framework OpenGL -framework Appkit
HEADERS = so_long.h
OBJS =	$(SRCS:.c=.o)

SRCS =	src/main.c \
		src/check_line.c \
		src/check_path.c \
		src/check_map.c \
		getnextline/get_next_line.c \
		getnextline/get_next_line_utils.c \
		src/so_long.c \
		src/movement.c \
		src/print_map.c \
		src/move_mob.c

all: $(NAME)
$(NAME): $(OBJS) mlx/libmlx.a
	gcc $(CFLAGS) -lz $(MLXFLAGS) $(OBJS) -o $(NAME)

mlx/libmlx.a:
	make -C ./mlx

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@ -I

clean:
	rm -f $(OBJS) $(OBJS_BNS)
	$(MAKE) clean -C mlx/

fclean: clean
	rm -f $(NAME) $(NAME_BNS)

re: fclean $(NAME)

.PHONY: clean fclean re
