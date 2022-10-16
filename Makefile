SRC			=	./fdf.c

H_SRC		=	fdf.h ./libft/libftprintf.h

NAME		=	fdf

LIBFT		=	./libft/libftprintf.a

FLAGS		=	-Wall -Wextra -Werror ./minilibx-linux/libmlx_Linux.a -L. -lXext -L. -lX11

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