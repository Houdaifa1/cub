NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -w

FLAGS =  -lmlx -lXext -lX11 -lm -lz

SOURCES = main.c

#FLAGS = ./minilibx/libmlx.a -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(SOURCES)
	cc $(CFLAGS) $(SOURCES) $(FLAGS) -o $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
