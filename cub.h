# ifndef CUB_H
# define CUB_H

# include <math.h>
# include "mlx.h"
//# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define cub_size 64
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
# define ROWS 19
# define COLS 24
# define line 20
# endif

//# define M_PI 3.14159265358979323846



typedef  struct mlx
{
    void    *mlx_ptr;
    void    *mlx_wind;

} t_mlx_ptrs;

typedef struct hit
{
    int hi;
    int hj;
    int vj;
    int vi;
    int ni;
    int nj;
    int lenght;
} t_wall_hit;

typedef struct player_info
{
    float         i;
    float         j;  
    float         new_i;
    float         new_j;
    int         move_direction;
    int         turn_direction;
    float       rotation_angle;
    float       move_speed;
    float       rotation_speed;
    int         fov_lenght;
    int         color;
    char        map[ROWS][COLS];
    t_mlx_ptrs  *mlx_ptrs;
    t_wall_hit  *wall_hit;

} t_player_info;


void cast_rays(t_player_info *player_infos);
void which_element(t_player_info *player_infos);
void find_inters_up_right_h(t_player_info *player_infos);
void find_inters_up_right_v(t_player_info *player_infos);
void find_inters_up_left_h(t_player_info *player_infos);
void find_inters_up_left_v(t_player_info *player_infos);
void find_inters_down_right_h(t_player_info *player_infos);
void find_inters_down_right_v(t_player_info *player_infos);
void find_inters_down_left_h(t_player_info *player_infos);
void find_inters_down_left_v(t_player_info *player_infos);
void find_nearest_wall_hit_down_left(t_player_info *player_infos);
void find_nearest_wall_hit_up_right(t_player_info *player_infos);
void find_nearest_wall_hit_down_right(t_player_info *player_infos);
void find_nearest_wall_hit_up_left(t_player_info *player_infos);





# endif