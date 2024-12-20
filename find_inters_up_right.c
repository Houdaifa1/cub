# include "cub.h"


void find_inters_up_right_h(t_player_info *player_infos)
{
    int x, y;
    float jsteps, isteps;
    int length;

    player_infos->wall_hit->hi = 0;
    player_infos->wall_hit->hj = 0;
    jsteps = ((int)player_infos->j / cub_size) * cub_size;    
    isteps = player_infos->i + (player_infos->j - jsteps) / fabs(tan(player_infos->rotation_angle));    
    y = ((int)jsteps - 1) / cub_size;
    x = ((int)isteps) / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->hi = isteps;
        player_infos->wall_hit->hj = jsteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        jsteps -= cub_size;
        isteps += cub_size / fabs(tan(player_infos->rotation_angle));
        y = ((int)jsteps - 1) / cub_size;
        x = ((int)isteps) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
    {
        player_infos->wall_hit->hi = isteps;
        player_infos->wall_hit->hj = jsteps;
    }
}

void find_inters_up_right_v(t_player_info *player_infos)
{
    int x, y;
    float jsteps, isteps;
    int length;

    player_infos->wall_hit->vi = 0;
    player_infos->wall_hit->vj = 0;
    isteps = ((int)player_infos->i / cub_size) * cub_size + cub_size;
    jsteps = player_infos->j - (isteps - player_infos->i) * fabs(tan(player_infos->rotation_angle));
    y = ((int)jsteps - 1) / cub_size;
    x = (int)isteps / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->vi = isteps;
        player_infos->wall_hit->vj = jsteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        isteps += cub_size;
        jsteps -= cub_size * fabs(tan(player_infos->rotation_angle));
        y = ((int)jsteps - 1) / cub_size;
        x = ((int)isteps) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
    {
        player_infos->wall_hit->vi = isteps;
        player_infos->wall_hit->vj = jsteps;
    }
}

void find_nearest_wall_hit_up_right(t_player_info *player_infos)
{
     printf("hj : %d  hi : %d                vj : %d   vi : %d\n", player_infos->wall_hit->hj, player_infos->wall_hit->hi, player_infos->wall_hit->vj, player_infos->wall_hit->vi);
    if (player_infos->wall_hit->vj == 0 || (player_infos->wall_hit->hj > player_infos->wall_hit->vj &&
        player_infos->wall_hit->hi < player_infos->wall_hit->vi))
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

