# include "cub.h"

// char map[player_infos->map_height][player_infos->map_width] = {
//   "111111111111111111111111",
//   "010000000000000000000001",
//   "1p1011111100001100000001",
//   "110000000000000000000001",
//   "101000010100000111110001",
//   "100000100010000000000001",
//   "100000010100000000000001",
//   "100000100010000000000001",
//   "100000100011100000000001",
//   "1000001000100000p0000001",
//   "100000000010000000000001",
//   "100000100010000111110001",
//   "100000100010000000000001",
//   "100000100010000000000001",
//   "100000100010000011110001",
//   "100000100010000000000001",
//   "100000100010001111000001",
//   "100000000000000000000001",
//   "111111111111111111111111",
// };


// void my_mlx_pixel_put( int x, int y, int color)
// {
//     char *dst;

//     // if (x < 0 || x >= game->map_width * TILE_SIZE || y < 0 || y >= game->map_height * TILE_SIZE)
//     //     return ;
//     dst = addr + (y * line_length + x * (bpp / 8));
    
//     *(unsigned int *)dst = color;
// }
// void my_mlx_pixel_put2(t_player_info *player_infos ,int x, int y, int color)
// {
//     char *dst;

//     char    *pixel;
//     int		i;

//     i = player_infos->bpp - 8;
//     pixel = player_infos->addr + (y * player_infos->line_length + x * (player_infos->bpp / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (player_infos->endian != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (player_infos->bpp - 8 - i)) & 0xFF;
//         i -= 8;
//     }

//     // if (x < 0 || x >= game->map_width * TILE_SIZE || y < 0 || y >= game->map_height * TILE_SIZE)
//     //     return ;
//    // dst = player_infos->addr + (y * player_infos->line_length + x * (player_infos->bpp / 8));
    
//    // *(unsigned int *)dst = color;
// }
// void draw_circle(t_mlx_ptrs *mlx_ptrs, t_player_info *player_infos, int radius, int color)
// {
//     int dx_limit;
//     int dy;
//     int dx;

//     dy = -radius;
//     while (dy <= radius)
//     {
//         dx_limit = sqrt(radius * radius - dy * dy);
//         dx = -dx_limit;
//         while (dx <= dx_limit)
//         {
//             my_mlx_pixel_put2(player_infos, (int)player_infos->i + dx, (int)player_infos->j + dy, color);
//             dx++;
//         }
//         dy++;
//     }
// }

// void draw_line_view(t_mlx_ptrs *mlx_ptrs,t_player_info *player_infos, int line_lenght, int color)
// {
//     float x1;
//     float y1;
//     int x;
//     int y;
   
//     while(line_lenght >= 2)
//     {
//         x1 = player_infos->i + cos(player_infos->rotation_angle) * line_lenght;
//         y1 = player_infos->j + sin(player_infos->rotation_angle) * line_lenght;
//         y = (int)y1 / CUB_SIZE;
//         x = (int)x1 / CUB_SIZE;
//         if (map[y][x] != '1')
//             my_mlx_pixel_put2(player_infos, (int)x1, (int)y1, color);
//         line_lenght--;
//     }
// }

// void new_player_pos(t_player_info *player_infos)
// {
//     player_infos->i = player_infos->i + cos(player_infos->rotation_angle) * player_infos->move_speed;
//     player_infos->j = player_infos->j + sin(player_infos->rotation_angle) * player_infos->move_speed;
// }



// void draw_pixels(t_mlx_ptrs *mlx_ptrs, int j, int i, t_player_info *player_infos)
// {
//     int x;
//     int y;

//     y = j * CUB_SIZE;
//     while(y < (j + 1) * CUB_SIZE)
//     {
//         x = i * CUB_SIZE ; 
//         while(x < (i + 1) * CUB_SIZE)
//         {
//             if (map[j][i] == '0')
//                 my_mlx_pixel_put2(player_infos, x , y, 0x000000);
//             if (map[j][i] == '1')
//                 my_mlx_pixel_put2( player_infos,x, y, 0xffffff);
//             if (map[j][i] == 'p')
//                 my_mlx_pixel_put2(player_infos, x , y, 0x000000);
//             x++;
//         }
//         y++;
//     }
// }

// void which_element(t_player_info *player_infos)
// {
//     int i;
//     int j;

//     j = 0;
//     while(j < player_infos->map_height)
//     {
//         i = 0;
//         while(i < player_infos->map_width)
//         {
//             if (map[j][i] == '1')
//                 draw_pixels(player_infos->mlx_ptrs, j, i, player_infos);
//             else if (map[j][i] == '0')
//                 draw_pixels(player_infos->mlx_ptrs, j, i, player_infos);
//             else if (map[j][i] == 'p')
//                 draw_pixels(player_infos->mlx_ptrs, j, i, player_infos);
//             i++;
//         }
//         j++;
//     }
// }



void player_new_pos(t_player_info *player_infos)
{
    int x;
    int y;
    float move_speed;
    float x1;
    float y1;

    y = player_infos->new_j / CUB_SIZE;
    x = player_infos->new_i / CUB_SIZE;
    move_speed = player_infos->move_speed;
    if (player_infos->map[y][x] == '1')
    {
        while(move_speed > 0)
        {
            x1 = player_infos->i + cos(player_infos->rotation_angle ) * (move_speed * -1);
            y1 = player_infos->j + sin(player_infos->rotation_angle ) * (move_speed * -1);
            y = y1 / CUB_SIZE;
            x = x1 / CUB_SIZE;
            if(player_infos->map[y][x] != '1')
            {
               
                player_infos->i = x1;
                player_infos->j = y1;
                return ; 
            }
            move_speed -= 0.1;
        }
    }
    else
    {
        player_infos->j = player_infos->new_j;
        player_infos->i = player_infos->new_i;
    }
}

void player_new_pos_up(t_player_info *player_infos)
{
    int x;
    int y;
    float move_speed;
    float x1;
    float y1;

    y = player_infos->new_j / CUB_SIZE;
    x = player_infos->new_i / CUB_SIZE;
    move_speed = player_infos->move_speed;
    if (player_infos->map[y][x] == '1')
    {
        while (move_speed > 0)
        {
            x1 = player_infos->i + cos(player_infos->rotation_angle) * (move_speed);
            y1 = player_infos->j + sin(player_infos->rotation_angle ) * (move_speed);
            y = (int)y1 / CUB_SIZE;
            x = (int)x1 / CUB_SIZE;
            if (player_infos->map[y][x] != '1')
            {
                player_infos->i = x1;
                player_infos->j = y1;
                return;
            }
            move_speed -= 0.1; 
        }
    }
    else
    {
        player_infos->j = player_infos->new_j;
        player_infos->i = player_infos->new_i;
    }
}


int game_loop(t_base *game)
{
    if (game->s_keys->left)
    {
        game->player_infos->rotation_angle += game->player_infos->rotation_speed * 1;
        if (game->player_infos->rotation_angle > (360 * (M_PI / 180)))
              game->player_infos->rotation_angle -= 360 * (M_PI / 180);
    }
    if(game->s_keys->right)
    {
        game->player_infos->rotation_angle += game->player_infos->rotation_speed * (-1);
        if (game->player_infos->rotation_angle < 0)
              game->player_infos->rotation_angle += 360 * (M_PI / 180);
    }
    if (game->s_keys->w)
    {
        game->player_infos->new_i = game->player_infos->i + cos(game->player_infos->rotation_angle) * game->player_infos->move_speed;
        game->player_infos->new_j = game->player_infos->j + sin(game->player_infos->rotation_angle) * game->player_infos->move_speed;
        player_new_pos_up(game->player_infos);
    }
    if (game->s_keys->s)
    {
        game->player_infos->new_i = game->player_infos->i + cos(game->player_infos->rotation_angle) * (game->player_infos->move_speed * -1);
        game->player_infos->new_j = game->player_infos->j + sin(game->player_infos->rotation_angle) * (game->player_infos->move_speed * -1);
        player_new_pos(game->player_infos);
    }
     if (game->s_keys->d) // 'd' key
    {
        game->player_infos->new_i = game->player_infos->i + cos(game->player_infos->rotation_angle + M_PI /2) * game->player_infos->move_speed;
        game->player_infos->new_j = game->player_infos->j + sin(game->player_infos->rotation_angle + M_PI /2) * game->player_infos->move_speed;
        player_new_pos(game->player_infos);
    }
    if (game->s_keys->a) // 'a' key
    {
        game->player_infos->new_i = game->player_infos->i + cos(game->player_infos->rotation_angle - M_PI / 2) * game->player_infos->move_speed;
        game->player_infos->new_j = game->player_infos->j + sin(game->player_infos->rotation_angle - M_PI / 2) * game->player_infos->move_speed;
        player_new_pos(game->player_infos);
    }
    draw_map(game);
    cast_rays(game);
    mlx_put_image_to_window(game->mlx_ptrs->mlx_ptr, game->mlx_ptrs->win, game->mlx_ptrs->img, 0, 0);
    return(0);
}



void get_player_pos(t_player_info *player_infos)
{
    int i;
    int j;

    j = 0;
    while(j < player_infos->map_height)
    {
        i = 0;
        while(i < player_infos->map_width)
        {
            if (player_infos->map[j][i] == 'N')
            {
                player_infos->i = (i + 0.5) * CUB_SIZE;
                player_infos->j = (j + 0.5) * CUB_SIZE;
                return;
            }
            i++;
        }
        j++;
    }
}

int main(int ac, char **av)
{
    t_mlx_ptrs mlx_ptrs;
    t_player_info player_infos;
    t_base game;

    if (ac != 2)
        return (1);
    //parsing
    ft_init_struct_game(&game);
    parsing(&game, av[1]);


    mlx_ptrs.mlx_ptr = mlx_init();
    mlx_ptrs.win = mlx_new_window(mlx_ptrs.mlx_ptr, game.map_width * CUB_SIZE, game.map_height * CUB_SIZE, "Cub3D");
    mlx_ptrs.img = mlx_new_image(mlx_ptrs.mlx_ptr, game.map_width * CUB_SIZE, game.map_height * CUB_SIZE);
    mlx_ptrs.addr = mlx_get_data_addr(mlx_ptrs.img, &mlx_ptrs.bpp, &mlx_ptrs.line_length, &mlx_ptrs.endian);

    // init game
    initialize_keys(&game);

   
    // draw map
    game.mlx_ptrs = &mlx_ptrs;
    mlx_hook(mlx_ptrs.win, 2, 1L << 0, key_press, &game);
    mlx_hook(mlx_ptrs.win, 3, 1L << 1, key_release, &game);
    draw_map(&game);


    // init_player_infos
    player_infos.map = game.map;
    player_infos.map_width = game.map_width;
    player_infos.map_height = game.map_height;
    player_infos.rotation_angle = (M_PI / 180) * 0;
    player_infos.rotation_speed = 1 * (M_PI / 180);
    player_infos.move_speed = 10;

    //which_element(&player_infos);
    game.player_infos = &player_infos;
    get_player_pos(&player_infos);
    //  printf("test_______________________________________________________hahaha\n");
    mlx_put_image_to_window(mlx_ptrs.mlx_ptr, mlx_ptrs.win, mlx_ptrs.img, 0, 0);
    mlx_loop_hook(game.mlx_ptrs->mlx_ptr, game_loop, &game);
    mlx_loop(mlx_ptrs.mlx_ptr);
    return(0);
}