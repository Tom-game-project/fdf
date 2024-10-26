# minilibx_test
NAME		=	minilibx_test
SRCS		=	src/fdf.c
MLX		=	mlx_Linux/libmlx.a
MLX_HEADER	=	mlx_Linux/mlx.h

OBJS 		=	$(SRCS:.c=.o)
# Compiler
CC			=	cc
LIBX_FLAGS	=	-Lminilibx-linux -lmlx -lXext -lX11
RM_FLAFS	=	-rf


# Rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

%.o:%.c $(MLX_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_HEADER): 
	@ git submodule init
	@ git submodule update

$(MLX):
	make -C minilibx-linux

clean:
	$(RM)  $(RM_FLAFS) minilibx-linux/
	$(RM) $(OBJS)
	mkdir minilibx-linux/

fclean:	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
