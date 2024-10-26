# minilibx_test
NAME		=	minilibx_test
SRCS		=	src/fdf.c
MLX		=	mlx_Linux/libmlx.a
OBJS 		=	$(SRCS:.c=.o)
# Compiler
CC			=	cc
LIBX_FLAGS	=	-Lminilibx-linux -lmlx -lXext -lX11

# Rules
all:		$(NAME)

$(NAME):	$(OBJS) $(MLX)
			$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

$(MLX):
	make -C minilibx-linux

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
