SRC			=	./src/fdf.c \
				./src/others/my_mlx_pixel_put.c \
				./src/draw_line/draw_line.c \
				./src/draw_line/asign_values.c \
				./src/draw_line/line_coordinates.c \
				./src/get_map/get_map.c \
				./src/get_map/read_file.c \
				./src/others/error_exit.c \
				./src/others/get_number.c \
				./src/others/mem_clear.c \
				./src/draw_map/draw_map.c \
				./src/draw_map/get_map_columns.c \
				./src/draw_map/get_map_lines.c \
				./src/draw_map/draw_isometric_line.c \
				./src/draw_map/get_depth.c \
				./src/others/ft_hextoi.c \
				./src/others/get_color.c \
				./src/hooks/close_window.c \
				./src/hooks/change_depth.c \
				./src/get_map/ft_hextoi_mod.c \
				./src/get_map/ft_atoi_mod.c \
				./src/get_map/dot_functions.c \
				./src/get_map/get_map_values.c \

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