# include "cub.h"




void draw_line2(t_base *game, int line_lenght, int color)
{
    float x1;
    float y1;
    int x;
    int y;
   
    while(line_lenght >= 2)
    {
        x1 = game->player_infos->i + cos(game->player_infos->ray_rotation_angle) * line_lenght;
        y1 = game->player_infos->j + sin(game->player_infos->ray_rotation_angle) * line_lenght;
        y = (int)y1 / CUB_SIZE;
        x = (int)x1 / CUB_SIZE;
        my_mlx_pixel_put(game, x1, y1, color);
       // mlx_pixel_put( player_infos->mlx_ptrs->mlx_ptr, player_infos->win, x1,y1, color);
        line_lenght--;
    }
}

int calculate_length(t_player_info *player_infos, float x, float y)
{
    return sqrt(pow(x - player_infos->i, 2) + pow(y - player_infos->j, 2));
}

void check_straight_ray(t_player_info *player_infos, int angle_of_ray)
{
    
    if (angle_of_ray == 0)
    {
        find_inters_right(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->j);
    }
    else if(angle_of_ray == 90)
    {
        find_inters_down(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->i, player_infos->wall_hit->nj);
    }
    else if (angle_of_ray == 180)
    {
        find_inters_left(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->j);
    }
    else if (angle_of_ray == 270)
    {
        find_inters_up(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->i, player_infos->wall_hit->nj);
    }
}

void find_wall_hit_h_v(t_player_info *player_infos)
{
    int angle_of_ray;
    int lenght;

   // which_element(player_infos);
    angle_of_ray = player_infos->ray_rotation_angle * 180/M_PI;
    
    check_straight_ray(player_infos, angle_of_ray);
      
     
    if (angle_of_ray > 0 && angle_of_ray < 90)
    {
        find_inters_down_right_h(player_infos);
        find_inters_down_right_v(player_infos);
        find_nearest_wall_hit_down_right(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
    }
    else if (angle_of_ray > 90 && angle_of_ray < 180)
    {
        find_inters_down_left_h(player_infos);
        find_inters_down_left_v(player_infos);
        find_nearest_wall_hit_down_left(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
    }
    else if (angle_of_ray > 180 && angle_of_ray < 270)
    {
        find_inters_up_left_h(player_infos);
        find_inters_up_left_v(player_infos);
        find_nearest_wall_hit_up_left(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);

    }
    else if (angle_of_ray > 270 && angle_of_ray < 360)
    {
        find_inters_up_right_h(player_infos);
        find_inters_up_right_v(player_infos);
        find_nearest_wall_hit_up_right(player_infos);
        player_infos->wall_hit->lenght = calculate_length(player_infos, player_infos->wall_hit->ni, player_infos->wall_hit->nj);
    }
}

void find_wall_hit_v()
{

}



void cast_rays(t_base *game)
{
    int start_angle_of_ray;
    int end_angle_of_ray;
    int angle_of_ray;
    int normal_angle;
    int i;


    game->player_infos->map = game->map;
    game->player_infos->map_width = game->map_width;
    game->player_infos->map_height = game->map_height;
    start_angle_of_ray = (game->player_infos->rotation_angle * 180/M_PI) - FOV/2;
    end_angle_of_ray = (game->player_infos->rotation_angle * 180/M_PI) + FOV/2;
    i = 0;
    angle_of_ray = start_angle_of_ray;
    while (angle_of_ray <= end_angle_of_ray)
    {
        normal_angle = (angle_of_ray + 360) % 360;
        game->player_infos->ray_rotation_angle = normal_angle * (M_PI / 180);
        find_wall_hit_h_v(game->player_infos);
        draw_line2(game, game->player_infos->wall_hit->lenght, 0xfff000);
        angle_of_ray++;
    }
   

}


// void cast_rays(t_player_info *player_infos) {
//     int start_angle = (player_infos->rotation_angle * 180 / M_PI) - FOV / 2;
//     int end_angle = (player_infos->rotation_angle * 180 / M_PI) + FOV / 2;

//     for (int angle_of_ray = start_angle; angle_of_ray <= end_angle; angle_of_ray++) {
//         int normalized_angle = (angle_of_ray + 360) % 360; // Normalize angle to be within 0-359 degrees
//         player_infos->ray_rotation_angle = normalized_angle * (M_PI / 180);
//         find_wall_hit_h_v(player_infos);
//     }
// }

// void cast_rays(t_player_info *player_infos) {
//     int angle_of_ray = (player_infos->rotation_angle * 180 / M_PI) - FOV / 2;

//     for (int i = 0; i <= FOV; i++) {
//         player_infos->ray_rotation_angle = (angle_of_ray + i) * (M_PI / 180);
//         find_wall_hit_h_v(player_infos);
//     }
// }