CFLAGS=-Wall -Wextra -Werror -std=c99
NAME=fdf
SRCS=$(addprefix src/, main.c)
OBJS=$(addprefix objects/, $(notdir $(SRCS:.c=.o)))
MLX=MLX42/build/libmlx42.a
LIBFT=libft/libft.a
LIBFT_FLAGS=-Llibft -lft
MLX_FLAGS=-LMLX42/build -lmlx42 -lm -ldl -lglfw -pthread

VPATH=src

all: $(NAME)
.PHONY: all

$(NAME): $(MLX) $(LIBFT) dir $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

objects/%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

$(MLX):
ifeq ($(shell ls ./MLX42/build), )
	@cmake -S ./MLX42 -B ./MLX42/build
endif
	@make -C MLX42/build

dir:
	@mkdir -p objects
.PHONY: dir

fclean: clean
	@rm -fr $(NAME)
	@make -C libft fclean
	@make -C MLX42/build clean
.PHONY: fclean

clean:
	@rm -fr objects
	@make -C libft clean
	@make -C MLX42/build clean
.PHONY: clean

re: fclean all
.PHONY: re

# test:
# 	cmake -S ./MLX42 -B ./MLX42/build
# 	cmake --build ./MLX42/build -j4
