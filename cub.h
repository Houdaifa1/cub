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
# define FOV 60
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
    float       ray_rotation_angle;
    float       move_speed;
    float       rotation_speed;
    int         fov_lenght;

    void    *mlx;           // Pointer to the MiniLibX connection
    void    *win;           // Pointer to the MiniLibX window
    void    *img;           // Pointer to the image
    char    *addr;          // Address of the image data
    int     bpp;            // Bits per pixel
    int     line_length;    // Number of bytes in a row
    int     endian;  
    int         color;
    char        map[ROWS][COLS];
    t_mlx_ptrs  *mlx_ptrs;
    t_wall_hit  *wall_hit;

} t_player_info;


// size_t  ft_strlen2(const char *s);
// void    parsing(t_base *game, char *file_name);
// int     ft_strncmp(const char *s1, const char *s2, size_t n);
// char	**ft_split(const char *s, char c);
// void	free_split(char **str);
// // void    ft_parse_texture(t_base *game, char **tokens);
// void ft_parse_texture(t_base *game, char *tokens);


// int parse_map(t_base *game, int fd);
// void    ft_printf_err(char *str);
// char	*ft_strdup(const char *s1);
// int parse_color(char *line);
// char	*ft_strtrim(char const *s1, char const *set);
// int	ft_isdigit(int i);
// void	*ft_memset(void *dest, int c, size_t count);
// int game_loop(t_base *game);
// void draw_map(t_base *game);
// void draw_square(t_base *game, int x, int y, int color);





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
void find_inters_right(t_player_info *player_infos);
void find_inters_left(t_player_info *player_infos);
void find_inters_up(t_player_info *player_infos);
void find_inters_down(t_player_info *player_infos);
void my_mlx_pixel_put2(t_player_info *player_infos ,int x, int y, int color);
void find_nearest_wall_hit_down_left(t_player_info *player_infos);
void find_nearest_wall_hit_up_right(t_player_info *player_infos);
void find_nearest_wall_hit_down_right(t_player_info *player_infos);
void find_nearest_wall_hit_up_left(t_player_info *player_infos);





# endif