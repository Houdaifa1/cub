# include "cub.h"


char map[ROWS][COLS] = {
        {'1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '1'},
        {'1', '0', '1', '1', '0', '1'},
        {'1', 'p', '1', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1'}
    };


// void draw_player_circle(void *mlx_ptr, void *mlx_wind, float j, float i)
// {
//     float x;
//     float y;

//     x = i * cub_size;
//     y = j * cub_size;
    
//     // float t1 = y;
//     // float t2 = x;
//     // while(y < t1 + 16)
//     // {
//     //     x = t2;
//     //     while(x < t2 + 16)
//     //     {
//             mlx_pixel_put(mlx_ptr, mlx_wind, x, y, 0xff0000);
//         //     x++;
//         // }
//         // y++;
//     //}

// }

// void    draw_player_circle(void *mlx_ptr, void *win_ptr, int y, int x)
// {
//     float radius = 5;
//     float x1 = 0, y1 = radius;
//     float d = 3 - 2 * radius;
//     int color = 0xff0000;

//     while (x1 <= y1)
//     {
//         mlx_pixel_put(mlx_ptr, win_ptr, x + x1, y + y1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x - x1, y + y1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x + x1, y - y1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x - x1, y - y1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x + y1, y + x1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x - y1, y + x1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x + y1, y - x1, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x - y1, y - x1, color);

//         if (d < 0)
//             d += 2 * x1 + 3;
//         else
//         {
//             d += 2 * (x1 - y1) + 5;
//             y1--;
//         }
//         x1++;
//     }
// }


// void draw_circle(void *mlx_ptr, void *win_ptr, int y0, int x0, int radius, int color) {
//     int x = radius, y = 0;
//     int err = 0;

//     while (x >= y) {
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 + y, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 + y, y0 + x, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 - y, y0 + x, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 - x, y0 + y, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 - x, y0 - y, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 - y, y0 - x, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 + y, y0 - x, color);
//         mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 - y, color);

//         y++;
//         err += 2*y + 1;
//         if (2*(err-x) + 1 > 0) {
//             x--;
//             err += 2*(1-x);
//         }
//     }
// }


void draw_circle(void *mlx_ptr, void *win_ptr, float y, float x, int radius, int color) {
    for (int dy = -radius; dy <= radius; dy++) {
        int dx_limit = sqrt(radius * radius - dy * dy); // Pythagoras theorem to calculate dx
        for (int dx = -dx_limit; dx <= dx_limit; dx++) {
            mlx_pixel_put(mlx_ptr, win_ptr, x + dx, y + dy, color);
        }
    }
}

void draw_line_view(void *mlx_ptr, void *mlx_wind, float y, float x, int line_lenght, int color)
{
    float rotation_angle;

    rotation_angle = M_PI / 2;
    float x1;
    float y1;
    while(line_lenght >= 1)
    {
        x1 = x + cos(rotation_angle) * line_lenght;
        y1 = y + sin(rotation_angle) * line_lenght;
        mlx_pixel_put(mlx_ptr, mlx_wind, x1, y1, 0xff0000);
        line_lenght--;
    }

}

void draw_pixels(void *mlx_ptr, void *mlx_wind, int j, int i)
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
                mlx_pixel_put(mlx_ptr, mlx_wind, x , y, 0x000000);
            if (map[j][i] == '1')
                mlx_pixel_put(mlx_ptr, mlx_wind, x, y, 0xffffff);
            if (map[j][i] == 'p')
            {
                draw_circle(mlx_ptr, mlx_wind, (j + 0.5) * cub_size, (i + 0.5) * cub_size, 3, 0xff0000);
                draw_line_view(mlx_ptr, mlx_wind, (j + 0.5) * cub_size, (i + 0.5) * cub_size, 15, 0xfff000);
                return ;
            }
            x++;
        }
        y++;
    }
}

void which_element(void *mlx_ptr, void *mlx_wind)
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
                draw_pixels(mlx_ptr, mlx_wind, j, i);
            else if (map[j][i] == '0')
                draw_pixels(mlx_ptr, mlx_wind, j, i);
            else if (map[j][i] == 'p')
                draw_pixels(mlx_ptr, mlx_wind, j, i);
            i++;
        }
        j++;
    }
}

int main()
{
    char *mlx_ptr;
    char *mlx_wind;
    
    mlx_ptr = mlx_init();
    mlx_wind = mlx_new_window(mlx_ptr, COLS * cub_size, ROWS * cub_size, "test");
    which_element(mlx_ptr, mlx_wind);
    mlx_loop(mlx_ptr);
    return(0);
}