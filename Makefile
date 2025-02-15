# Compile option
CC		=	cc
CFLAGS		=	-Wextra -Werror -Wall -g -DBUFFER_SIZE=1024
LIBX_FLAGS	=	-Lminilibx-linux -lmlx -lXext -lX11
RM_FLAGS	=	-rf

## ------------------ entry point ---------------------
NAME		=	fdf
MAIN_SRC	=	src/fdf.c

## --------------------- draw --------------------------
DRAW_SRC	=	src/draw/draw_line.c\
			src/draw/draw_line_helper00.c\
			src/draw/draw_line_helper01.c\
			src/draw/draw_lines.c\
			src/draw/draw_map.c\
			src/draw/draw_point.c

## --------------------- data ---------------------------
DATA_SRC	=	src/data/i32u32_encode.c\
			src/data/i32u32_decode.c\
			src/data/u32x2_ope_basic.c\
			src/data/u32x2_encode.c\
			src/data/u32x2_decode.c\
			src/data/i32x2_encode.c\
			src/data/i32x2_decode.c\
			src/data/i32x2_ope_basic.c\
			src/data/i32x2_ope_extra.c\
			src/data/i32x2_complex.c\
			src/data/u8x4_encode.c\
			src/data/u8x4_decode.c\
			src/data/u8x4_ope_basic.c\
			src/data/u16x4_encode.c\
			src/data/u16x4_decode.c\
			src/data/u16x4_ope_basic.c\
			src/data/u16x4_ope_extra.c\
			src/data/u16x4_ope_color.c\
			src/data/vec2d_64.c\
			src/data/vec2d_64_ope_basic.c

## ----------------- fdf loader ------------------------
FDF_LOADER_SRC	=	src/fdf_loader/loader.c\
			src/fdf_loader/gnl/get_next_line.c\
			src/fdf_loader/gnl/get_next_line_utils.c\
			src/fdf_loader/loader_helper00.c\
			src/fdf_loader/loader_helper01.c\
			src/fdf_loader/loader_helper02.c\
			src/fdf_loader/checker.c

## --------------------- error -------------------------
ERROR_SRC	=	src/error/result.c\
			src/error/error_msg00.c\
			src/error/error_msg01.c

## --------------------- hook ---------------------------
HOOK_SRC	=	src/hook/hook_helper00.c\
			src/hook/hook.c

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++
# main src
SRCS		=	$(DRAW_SRC)\
			$(DATA_SRC)\
			$(FDF_LOADER_SRC)\
			$(ERROR_SRC)\
			$(HOOK_SRC)

# for test
TEST		=	test_run
TEST_SRCS	=	tests/test_u32x2.c

# objects
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
OBJS 		=	$(SRCS:.c=.o)
TEST_OBJS	=	$(TEST_SRCS:.c=.o)

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++
# third party
## mlx tools
MLX		=	minilibx-linux/libmlx.a
MLX_HEADER	=	minilibx-linux/mlx.h

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Debug

VALGRIND	=	valgrind
VFLAGS		=	--leak-check=full -q
SHA		=	sha256sum

# -------------- Test map Install Tools ---------------
TEST_MAPS	=	maps/
TEST_MAPS_ZIP	=	maps.zip

# Rules
all: $(NAME)

bonus: $(NAME)

test: $(TEST)
	$(SHA) $(TEST)
	#./$(TEST)
	$(VALGRIND) $(VFLAGS) ./$(TEST)

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

clean: cleanmaps
	$(RM) $(RM_FLAGS) $(MAIN_OBJ)
	$(RM) $(RM_FLAGS) minilibx-linux/
	$(RM) $(RM_FLAGS) $(OBJS)
	mkdir minilibx-linux/

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)
	$(RM) $(RM_FLAGS) $(TEST_MAPS_ZIP)

re: fclean all

# ------ Test map Install Tools ----------

$(TEST_MAPS_ZIP): 
	wget https://cdn.intra.42.fr/document/document/27142/maps.zip

$(TEST_MAPS): $(TEST_MAPS_ZIP)
	mkdir -p $(TEST_MAPS)
	unzip $(TEST_MAPS_ZIP) -d $(TEST_MAPS)

installmaps: $(TEST_MAPS)

cleanmaps: 
	$(RM) $(RM_FLAGS) $(TEST_MAPS)

reinstallmaps: cleanmaps installmaps

.PHONY: all clean fclean re test installmaps cleanmaps bonus
