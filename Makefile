SRC			=	my_mlx_pixel_put.c \
				draw_line.c \
				asign_values.c \
				line_coordinates.c \
				get_map.c \
				read_file.c \
				error_exit.c \
				get_number.c \
				mem_clear.c \
				finish_program.c \
				draw_map.c \
				get_map_columns.c \
				get_map_lines.c \
				draw_isometric_line.c \
				get_depth.c \
				ft_hextoi.c \
				get_color.c \
				close_window_x.c \
				key_hooks.c \
				ft_hextoi_mod.c \
				ft_atoi_mod.c \
				dot_functions.c \
				get_map_values.c \
				image_minimum_size.c \
				extract_color.c \
				calculate_tile_size.c \


H_SRC		=	./src/fdf.h ./libft/libftprintf.h

OBJS_DIR			=	objects
OBJS				=	$(patsubst %.c,objects/%.o, $(SRC))

NAME		=	fdf

LIBFT		=	./libft/libftprintf.a

CFLAGS		=	-L. -lXext -L. -lX11

VPATH				=	./src/others \
						./src/draw_line \
						./src/draw_map \
						./src \
						./src/hooks \
						./ \
						./src/get_map \

$(OBJS_DIR)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(OBJS_DIR):
						mkdir -p $@

$(NAME): $(OBJS_DIR) $(OBJS) $(H_SRC) $(LIBFT)
	gcc ./src/fdf.c ${OBJS} ${CFLAGS} ${LIBFT} -o $@
	

$(LIBFT):
	make -C ./libft bonus

clean:
	rm -rf ${OBJS_DIR}
	make -C ./libft clean

fclean:	clean
	rm -f ${NAME}
	make -C ./libft fclean

re: fclean all

.PHONY:	all clean fclean re