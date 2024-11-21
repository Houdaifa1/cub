# ifndef CUB_H
# define CUB_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include "./minilibx-linux/mlx.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define cub_size 96
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
# define ROWS 6
# define COLS 6
# endif

# define M_PI 3.14159265358979323846

typedef struct player_info {
int     move_direction;
int     turn_direction;
float   rotation_angle;
float   move_speed;
float   rotation_speed;
} t_player_info;


# endif