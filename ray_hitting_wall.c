# include "cub.h"


void draw_line(t_mlx_ptrs *mlx_ptrs,t_player_info *player_infos, int line_lenght, int color)
{
    float x1;
    float y1;
    int x;
    int y;
   
    while(line_lenght >= 2)
    {
        x1 = player_infos->i + cos(player_infos->rotation_angle) * line_lenght;
        y1 = player_infos->j + sin(player_infos->rotation_angle) * line_lenght;
        y = (int)y1 / cub_size;
        x = (int)x1 / cub_size;
        mlx_pixel_put(mlx_ptrs->mlx_ptr, mlx_ptrs->mlx_wind, x1, y1, color);
        line_lenght--;
    }
}

int calculate_length(t_player_info *player_infos, float x, float y)
{
    return sqrt(pow(x - player_infos->i, 2) + pow(y - player_infos->j, 2));
}







void find_wall_hit_h_v(t_player_info *player_infos)
{
    int angle_of_ray;
    int lenght;

    //which_element(player_infos);
    angle_of_ray = player_infos->rotation_angle * 180/M_PI;
    if (angle_of_ray > 0 && angle_of_ray < 90)
    {
        find_inters_down_right_h(player_infos);
        find_inters_down_right_v(player_infos);
        find_nearest_wall_hit_down_right(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
        draw_line(player_infos->mlx_ptrs, player_infos, player_infos->wall_hit->lenght, 0xfff000);
    }
    else if (angle_of_ray > 90 && angle_of_ray < 180)
    {
        find_inters_down_left_h(player_infos);
        find_inters_down_left_v(player_infos);
        find_nearest_wall_hit_down_left(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
        draw_line(player_infos->mlx_ptrs, player_infos, player_infos->wall_hit->lenght, 0xfff000);
    }
    else if (angle_of_ray > 180 && angle_of_ray < 270)
    {
        find_inters_up_left_h(player_infos);
        find_inters_up_left_v(player_infos);
        find_nearest_wall_hit_up_left(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
        draw_line(player_infos->mlx_ptrs, player_infos, player_infos->wall_hit->lenght, 0xfff000);

    }
    else if (angle_of_ray > 270 && angle_of_ray < 360)
    {
        find_inters_up_right_h(player_infos);
        find_inters_up_right_v(player_infos);
        find_nearest_wall_hit_up_right(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
        draw_line(player_infos->mlx_ptrs, player_infos, player_infos->wall_hit->lenght, 0xfff000);
    }
}

void find_wall_hit_v()
{

}



void cast_rays(t_player_info *player_infos)
{
    int lenght;

    find_wall_hit_h_v(player_infos);
   

}