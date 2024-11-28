# include "cub.h"

char map[ROWS][COLS] = {
  "111111111111111111111111",
  "1p0000000000000000000001",
  "100001111111000110000001",
  "100000000000000000000001",
  "100000100000000111110001",
  "100000100010000000000001",
  "100000000010000000000001",
  "100000100010000000000001",
  "100000100011100000000001",
  "1000001000100000p0000001",
  "100000000010000000000001",
  "100000100010000111110001",
  "100000100010000000000001",
  "100000100010000000000001",
  "100000100010000011110001",
  "100000100010000000000001",
  "100000100010001111000001",
  "100000000000000000000001",
  "111111111111111111111111",
};

void draw_circle(t_mlx_ptrs *mlx_ptrs, t_player_info *player_infos, int radius, int color)
{
    int dx_limit;
    int dy;
    int dx;

    dy = -radius;
    while (dy <= radius)
    {
        dx_limit = sqrt(radius * radius - dy * dy);
        dx = -dx_limit;
        while (dx <= dx_limit)
        {
            mlx_pixel_put(mlx_ptrs->mlx_ptr, mlx_ptrs->mlx_wind, player_infos->i + dx, player_infos->j + dy, color);
            dx++;
        }
        dy++;
    }
}

void draw_line_view(t_mlx_ptrs *mlx_ptrs,t_player_info *player_infos, int line_lenght, int color)
{
    float x1;
    float y1;
   
    while(line_lenght >= 2)
    {
        x1 = player_infos->i + cos(player_infos->rotation_angle) * line_lenght;
        y1 = player_infos->j + sin(player_infos->rotation_angle) * line_lenght;
        mlx_pixel_put(mlx_ptrs->mlx_ptr, mlx_ptrs->mlx_wind, x1, y1, color);
        line_lenght--;
    }
}
void new_player_pos(t_player_info *player_infos)
{
    player_infos->i = player_infos->i + cos(player_infos->rotation_angle) * player_infos->move_speed;
    player_infos->j = player_infos->j + sin(player_infos->rotation_angle) * player_infos->move_speed;
}
void draw_pixels(t_mlx_ptrs *mlx_ptrs, int j, int i, t_player_info *player_infos)
{
    int x;
    int y;

    y = j * cub_size;
    while(y < (j + 1) * cub_size)
    {
        x = i * cub_size ; 
        while(x < (i + 1) * cub_size)
        {
            if (map[j][i] == '0')
                mlx_pixel_put(mlx_ptrs->mlx_ptr, mlx_ptrs->mlx_wind, x , y, 0x000000);
            if (map[j][i] == '1')
                mlx_pixel_put(mlx_ptrs->mlx_ptr, mlx_ptrs->mlx_wind, x, y, 0xffffff);
            if (map[j][i] == 'p')
                mlx_pixel_put(mlx_ptrs->mlx_ptr, mlx_ptrs->mlx_wind, x , y, 0x000000);
            x++;
        }
        y++;
    }
}

void which_element(t_mlx_ptrs *mlx_ptrs, t_player_info *player_infos)
{
    int i;
    int j;

    j = 0;
    while(j < ROWS)
    {
        i = 0;
        while(i < COLS)
        {
            if (map[j][i] == '1')
                draw_pixels(mlx_ptrs, j, i, player_infos);
            else if (map[j][i] == '0')
                draw_pixels(mlx_ptrs, j, i, player_infos);
            else if (map[j][i] == 'p')
                draw_pixels(mlx_ptrs, j, i, player_infos);
            i++;
        }
        j++;
    }
}

void check_player_new_pos(t_player_info *player_infos)
{
    int x;
    int y;
    int move_speed;

    y = player_infos->new_j / cub_size;
    x = player_infos->new_i / cub_size;
    if (map[y][x] != '1')
    {
        // if (player_infos->new_i != player_infos->i)
        // {
        //     move_speed = player_infos->i - (32 * (player_infos->i / 32)) + 1;
        //     player_infos->i = player_infos->i + cos(player_infos->rotation_angle) * move_speed; 
        // }
        // else
            player_infos->i = player_infos->new_i;
        // if (player_infos->new_i != player_infos->i)
        // {
        //     move_speed = player_infos->j - (32 * (player_infos->j / 32)) + 1;
        //     player_infos->j = player_infos->j + sin(player_infos->rotation_angle) * move_speed; 
        // }
        // else
            player_infos->j = player_infos->new_j;
    }
    //else
    // {
    //     player_infos->j = player_infos->new_j;
    //     player_infos->i = player_infos->new_i;
    // }
}
int handlle_keys(int keynum, t_player_info *player_infos)
{
    if (keynum == 124)
    {
        which_element(player_infos->mlx_ptrs, player_infos);
        player_infos->rotation_angle += player_infos->rotation_speed * 1;   
        draw_line_view(player_infos->mlx_ptrs, player_infos, line, 0xff0000);
        draw_circle(player_infos->mlx_ptrs, player_infos, 2, 0xfff000);
        
    }
    if(keynum == 123)
    {
        which_element(player_infos->mlx_ptrs, player_infos);
        player_infos->rotation_angle += player_infos->rotation_speed * (-1);
        draw_line_view(player_infos->mlx_ptrs, player_infos, line, 0xff0000);
        draw_circle(player_infos->mlx_ptrs, player_infos, 2, 0xfff000);
    }
    if (keynum == 13)
    {
        which_element(player_infos->mlx_ptrs, player_infos);
        player_infos->new_i = player_infos->i + cos(player_infos->rotation_angle) * player_infos->move_speed;
        player_infos->new_j = player_infos->j + sin(player_infos->rotation_angle) * player_infos->move_speed;
        check_player_new_pos(player_infos);
        draw_line_view(player_infos->mlx_ptrs, player_infos, line, 0xff0000);
        draw_circle(player_infos->mlx_ptrs, player_infos, 2, 0xfff000);
    }
    if (keynum == 1)
    {
        which_element(player_infos->mlx_ptrs, player_infos);
        player_infos->new_i = player_infos->i + cos(player_infos->rotation_angle) * (player_infos->move_speed * -1);
        player_infos->new_j = player_infos->j + sin(player_infos->rotation_angle) * (player_infos->move_speed * -1);
        check_player_new_pos(player_infos);
        draw_line_view(player_infos->mlx_ptrs, player_infos, line, 0xff0000);
        draw_circle(player_infos->mlx_ptrs, player_infos, 2, 0xfff000);
    }
    if (keynum == 53)
    {
        exit(1);
    }
    return(0);
}

handlle_rotation(t_mlx_ptrs *mlx_ptrs, t_player_info *player_infos)
{
    mlx_hook(mlx_ptrs->mlx_wind, 02, 1L<<0, handlle_keys, player_infos);
}

void get_player_pos(t_player_info *player_infos)
{
    int i;
    int j;

    j = 0;
    while(j < ROWS)
    {
        i = 0;
        while(i < COLS)
        {
            if (map[j][i] == 'p')
            {
                player_infos->i = (i + 0.5) * cub_size;
                player_infos->j = (j + 0.5) * cub_size;
                draw_circle(player_infos->mlx_ptrs, player_infos, 2, 0xfff000);
                draw_line_view(player_infos->mlx_ptrs, player_infos, line, 0xff0000);
                return;
            }
            i++;
        }
        j++;
    }
}

int main()
{
    t_mlx_ptrs mlx_ptrs;
    t_player_info player_infos;
    
    mlx_ptrs.mlx_ptr = mlx_init();
    mlx_ptrs.mlx_wind = mlx_new_window(mlx_ptrs.mlx_ptr, COLS * cub_size, ROWS * cub_size, "test");
    player_infos.rotation_angle = (M_PI / 180) * 180;
    player_infos.rotation_speed = 60 * (M_PI / 180);
    player_infos.move_speed = 10;
    player_infos.mlx_ptrs = &mlx_ptrs;
    which_element(&mlx_ptrs, &player_infos);
    get_player_pos(&player_infos);
    handlle_rotation(&mlx_ptrs, &player_infos);
    mlx_loop(mlx_ptrs.mlx_ptr);
    return(0);
}