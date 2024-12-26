NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -w

FLAGS =  -lmlx -lXext -lX11 -lm -lz 

SOURCES = main.c ray_hitting_wall.c find_inters_up_right.c find_inters_up_left.c find_inters_down_right.c find_inters_down_left.c find_inters_straight.c 

#FLAGS = ./minilibx/libmlx.a -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(SOURCES)
	cc $(CFLAGS) $(SOURCES) $(FLAGS) -o $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
