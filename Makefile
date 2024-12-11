# minilibx_test
NAME		=	fdf
SRCS		=	src/fdf.c
MLX		=	minilibx-linux/libmlx.a
MLX_HEADER	=	minilibx-linux/mlx.h

OBJS 		=	$(SRCS:.c=.o)
# Compiler
CC		=	cc
CFLAGS		=	-Wextra -Werror -Wall -g
LIBX_FLAGS	=	-Lminilibx-linux -lmlx -lXext -lX11
RM_FLAGS	=	-rf

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

%.o: %.c $(MLX_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Minilibx の更新チェック
$(MLX_HEADER): 
	@ git submodule init
	@ git submodule update

# Minilibx のビルド
$(MLX):
	make -C minilibx-linux

clean:
	$(RM) $(RM_FLAGS) minilibx-linux/
	$(RM) $(RM_FLAGS) $(OBJS)
	mkdir minilibx-linux/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

