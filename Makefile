# minilibx_test
NAME		=	fdf
MAIN_SRC	=	src/fdf.c
SRCS		=	src/draw/draw_line.c\
			src/data/i32u32.c\
			src/data/u32x2.c\
			src/data/i32x2.c\
			src/data/vec2d_64.c\
			src/fdf_loader/loader.c\
			src/fdf_loader/gnl/get_next_line.c\
			src/fdf_loader/gnl/get_next_line_utils.c

# for test
TEST		=	test_run
TEST_SRCS	=	tests/test_u32x2.c

# mlx tools
MLX		=	minilibx-linux/libmlx.a
MLX_HEADER	=	minilibx-linux/mlx.h

# objects
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
OBJS 		=	$(SRCS:.c=.o)
TEST_OBJS	=	$(TEST_SRCS:.c=.o)

# Compiler option
CC		=	cc
CFLAGS		=	-Wextra -Werror -Wall -g
LIBX_FLAGS	=	-Lminilibx-linux -lmlx -lXext -lX11
RM_FLAGS	=	-rf


# Debug

VALGRIND	=	valgrind
VFLAGS		=	--leak-check=full  -q
SHA		=	sha256sum


# Rules
all: $(NAME)

test: $(TEST)
	@ $(SHA) $(TEST)
	@ $(VALGRIND) $(VFLAGS) ./$(TEST)

$(TEST): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(OBJS) $(LIBX_FLAGS) -o $(TEST)

$(NAME): $(MAIN_OBJ) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

%.o: %.c $(MLX_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Minilibx の更新チェック
$(MLX_HEADER): 
	@ git submodule init
	@ git submodule update

# Minilibx のビルド
$(MLX):
	$(MAKE) -C minilibx-linux

clean:
	$(RM) $(RM_FLAGS) minilibx-linux/
	$(RM) $(RM_FLAGS) $(OBJS)
	mkdir minilibx-linux/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test

