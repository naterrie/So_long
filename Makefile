NAME =	so_long
CFLAGS =	-Wall -Werror -Wextra -fsanitize=address -g3
MLXFLAGS =	-L mlx -lmlx -framework OpenGL -framework Appkit
HEADERS = so_long.h
OBJS =	$(SRCS:.c=.o)

SRCS =	main.c \
		check_line.c \
		check_path.c \
		check_map.c \
		getnextline/get_next_line.c \
		getnextline/get_next_line_utils.c \
		so_long.c \
		movement.c \
		to_delete.c

all: $(NAME)
$(NAME): $(OBJS)
	gcc $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@ -I

clean:
	rm -f $(OBJS) $(OBJS_BNS)

fclean: clean
	rm -f $(NAME) $(NAME_BNS)

re: fclean $(NAME)

.PHONY: clean fclean re
