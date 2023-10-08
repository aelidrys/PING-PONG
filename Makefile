NAME = ping_pong

CC = cc

OBJ = src/get_next_line_utils.o src/get_next_line.o\
src/main.o src/movment.o src/pixils.o src/event.o src/put.o src/split.o\
src/init_var.o src/motion.o src/mouse.o src/boot.o

FLAG = -fsanitize=address -g

MLX_MFLAG = -lmlx -framework OpenGL -framework AppKit -lm

MLX_UFLAG = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

build : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ)  -o $(NAME) $(MLX_MFLAG)

%.o:%.c
	$(CC) -c -o $@ $<

clean :
	rm -rf $(OBJ)

clean_all : clean
	rm -rf $(NAME)

re : clean_all build
