# include "cub.h"

void find_inters_right(t_player_info *player_infos)
{
    int x, y;
    float  isteps;
    int length;
   
    isteps = ((int)player_infos->i / cub_size) * cub_size + cub_size;    
    y = ((int)player_infos->j) / cub_size;
    x = ((int)isteps) / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->ni = isteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        isteps += cub_size;
        y = ((int)player_infos->j) / cub_size;
        x = ((int)isteps) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
        player_infos->wall_hit->ni = isteps;
}

void find_inters_down(t_player_info *player_infos)
{
    int x, y;
    float  jsteps;
    int length;
   
    jsteps = ((int)player_infos->j / cub_size) * cub_size + cub_size;    
    x = ((int)player_infos->i) / cub_size;
    y = ((int)jsteps) / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->nj = jsteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        jsteps += cub_size;
        x = ((int)player_infos->i) / cub_size;
        y = ((int)jsteps) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
        player_infos->wall_hit->nj = jsteps;


}

void find_inters_left(t_player_info *player_infos)
{
    int x, y;
    float  isteps;
    int length;
   
    isteps = ((int)player_infos->i / cub_size) * cub_size;    
    y = ((int)player_infos->j) / cub_size;
    x = ((int)isteps - 1) / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->ni = isteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        isteps -= cub_size;
        y = ((int)player_infos->j) / cub_size;
        x = ((int)isteps - 1) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
        player_infos->wall_hit->ni = isteps;
    

}

void find_inters_up(t_player_info *player_infos)
{
    int x, y;
    float  jsteps;
    int length;
   
    jsteps = ((int)player_infos->j / cub_size) * cub_size;    
    x = ((int)player_infos->i) / cub_size;
    y = ((int)jsteps - 1) / cub_size;
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] == '1')
    {
        player_infos->wall_hit->nj = jsteps;
        return;
    }
    while (y >= 0 && y < ROWS && x >= 0 && x < COLS && player_infos->map[y][x] != '1')
    {
        jsteps -= cub_size;
        x = ((int)player_infos->i) / cub_size;
        y = ((int)jsteps -1) / cub_size;
    }
    if (y >= 0 && y < ROWS && x >= 0 && x < COLS)
        player_infos->wall_hit->nj = jsteps;

}