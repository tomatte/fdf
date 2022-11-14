SRC			=	./src/fdf.c \
				./src/others/my_mlx_pixel_put.c \
				./src/draw_line/draw_line.c \
				./src/draw_line/asign_values.c \
				./src/draw_line/line_coordinates.c \
				./src/get_map/get_map.c \
				./src/get_map/read_file.c \
				./src/others/error_exit.c \
				./src/others/get_number.c \

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