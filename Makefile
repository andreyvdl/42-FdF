# VARS ========================================================================
NAME=fdf
FLAGS=-Wall -Wextra -Werror -g3
LIBFT=libft/libft.a
MLX_GIT="https://github.com/codam-coding-college/MLX42.git"
MLX_FLAGS=-ldl -lglfw -pthread -lm
MLX=MLX42/build/libmlx42.a

all: ${MLX} ${NAME}

${MLX}:
	@if (test -d MLX42); then \
		printf "\e[1;32mMLX42 already cloned!\e[0m\n";\
	else \
		git clone ${MLX_GIT};\
	fi
	sed -i "s/(VERSION 3.18.0)/(VERSION 3.16.0)/" MLX42/CMakeLists.txt
	cmake -S MLX42 -B MLX42/build
	make -C MLX42/build

${LIBFT}:
	make -C libft

${NAME}: ${MLX} ${LIBFT} 
	@if (./include/fdf.h -nt ${NAME}); then \
		make re; \
	else \
		printf "\e[1;32mAlready Updated!\e[0m\n"; \
	fi
