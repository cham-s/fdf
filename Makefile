NAME = fdf 
CC = clang
LIB = libft/libft.a
FLAGS = -g -Wall -Werror -Wextra 
LIBGRPH = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I includes -I libft/includes -I minilibx_macos
OBJS = main.o draw.o parsing.o getpoint.o line.o matrix.o handler.o init.o transfo.o
.PHONY: all clean fclean re

VPATH = sources/:minilibx_macos

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
	make -C libft/
	make -C minilibx_macos

%.o : %.c 
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	make clean -C minilibx_macos
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
