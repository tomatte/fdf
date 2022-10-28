SRC			=	./src/fdf_test.c ./src/my_mlx_pixel_put.c ./src/line/draw_line.c \
				./src/line/asign_values.c ./src/line/line_coordinates.c \
				./src/draw_table/get_next_coordinates.c \
				./src/draw_table/draw_map_line.c ./src/draw_table/draw_map.c \
				./src/draw_table/get_line_size.c ./src/draw_table/draw_map_column.c \


H_SRC		=	./src/fdf.h ./libft/libftprintf.h

NAME		=	fdf

LIBFT		=	./libft/libftprintf.a

FLAGS		=	./minilibx-linux/libmlx_Linux.a -L. -lXext -L. -lX11

all: $(NAME)

$(NAME): $(OBJS) $(H_SRC) $(LIBFT)
	gcc ${SRC} ${FLAGS} ${LIBFT} -o $@ 
	

$(LIBFT):
	make -C ./libft bonus

clean:
	rm -f ${OBJS}
	make -C ./libft clean

fclean:	clean
	rm -f ${NAME}
	make -C ./libft fclean

re: fclean all

.PHONY:	all clean fclean re