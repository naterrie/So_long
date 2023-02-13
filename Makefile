NAME =	so_long
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
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

all: $(NAME) Makefile
$(NAME): $(OBJS) mlx/libmlx.a
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS)

mlx/libmlx.a:
	make -C ./mlx

%.o: %.c $(HEADERS)
	cc $(CFLAGS) -I -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BNS)
	$(MAKE) clean -C mlx/

fclean: clean
	rm -f $(NAME) $(NAME_BNS)

re: fclean $(NAME)

.PHONY: clean fclean re
