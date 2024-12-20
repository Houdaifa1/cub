# include "cub.h"




void find_inters_down_left_h(t_player_info *player_infos)
{
    int x, y;
    float jsteps, isteps;
    int length;

    player_infos->wall_hit->hi = -1;
    player_infos->wall_hit->hj = -1;
    jsteps = ((int)player_infos->j / cub_size) * cub_size + cub_size;    
    isteps = player_infos->i - (jsteps - player_infos->j) / fabs(tan(player_infos->rotation_angle));    
    y = ((int)jsteps) / cub_size;
    x = ((int)isteps) / cub_size;
    printf("y : %d                      x : %d\n", y, x );
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->hi = isteps;
        player_infos->wall_hit->hj = jsteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        jsteps += cub_size;
        isteps -= cub_size / fabs(tan(player_infos->rotation_angle));
        y = ((int)jsteps) / cub_size;
        x = ((int)isteps) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
    {
        player_infos->wall_hit->hi = isteps;
        player_infos->wall_hit->hj = jsteps;
    }
}

void find_inters_down_left_v(t_player_info *player_infos)
{
    int x, y;
    float jsteps, isteps;
    int length;

    player_infos->wall_hit->vi = -1;
    player_infos->wall_hit->vj = -1;
    isteps = ((int)player_infos->i / cub_size) * cub_size;
    jsteps = player_infos->j + (player_infos->i - isteps) * fabs(tan(player_infos->rotation_angle));
    y = ((int)jsteps) / cub_size;
    x = ((int)isteps - 1) / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->vi = isteps;
        player_infos->wall_hit->vj = jsteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        isteps -= cub_size;
        jsteps += cub_size * fabs(tan(player_infos->rotation_angle));
        y = ((int)jsteps ) / cub_size;
        x = (((int)isteps) - 1) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
    {
        player_infos->wall_hit->vi = isteps;
        player_infos->wall_hit->vj = jsteps;
    }
}

void find_nearest_wall_hit_down_left(t_player_info *player_infos)
{
     printf("hj : %d  hi : %d                vj : %d   vi : %d\n", player_infos->wall_hit->hj, player_infos->wall_hit->hi, player_infos->wall_hit->vj, player_infos->wall_hit->vi);
    if (player_infos->wall_hit->hi == -1 || player_infos->wall_hit->hj == -1)
    {
        player_infos->wall_hit->nj = player_infos->wall_hit->vj;
        player_infos->wall_hit->ni = player_infos->wall_hit->vi;
    }
    else if (player_infos->wall_hit->vi == -1 || player_infos->wall_hit->vj == -1)
    {
        player_infos->wall_hit->nj = player_infos->wall_hit->hj;
        player_infos->wall_hit->ni = player_infos->wall_hit->hi;
    }
    else if (player_infos->wall_hit->hj < player_infos->wall_hit->vj &&
        player_infos->wall_hit->hi > player_infos->wall_hit->vi)
    {
        player_infos->wall_hit->nj = player_infos->wall_hit->hj;
        player_infos->wall_hit->ni = player_infos->wall_hit->hi;
    }
    else
    {
        player_infos->wall_hit->nj = player_infos->wall_hit->vj;
        player_infos->wall_hit->ni = player_infos->wall_hit->vi;
    }
}

