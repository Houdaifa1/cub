NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -w

FLAGS =  -lmlx -lXext -lX11 -lm -lz 

RAY_CASTING = main.c ray_hitting_wall.c find_inters_up_right.c\
			find_inters_up_left.c find_inters_down_right.c \
			find_inters_down_left.c find_inters_straight.c \
			
			
PARSING =	parsing/intialize_game.c parsing/parsing.c\
			parsing/parsing2.c parsing/check_texture_rgb.c \
			parsing/ft_split.c parsing/utils.c  parsing/utils_lib.c  \
			./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c \

			


#FLAGS = ./minilibx/libmlx.a -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(RAY_CASTING) $(PARSING)
	cc $(CFLAGS) $(RAY_CASTING) $(PARSING) $(FLAGS) -o $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
