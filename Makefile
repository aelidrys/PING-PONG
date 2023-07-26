NAME = ping_pong

OBJ = get_next_line/get_next_line.o get_next_line/get_next_line_utils.o\
main.o movment.o pixils.o event.o put.o split.o

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g

build = $(NAME)

$(NAME) : $(OBJ)
	gcc $(MLX_FLAG) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

clean_all : clean
	rm -rf $(OBJ)
	rm -rf $(NAME)