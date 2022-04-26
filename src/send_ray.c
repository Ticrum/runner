/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** send_ray - 2021
**
** *****************************************************************************
*/

#include "runner.h"

t_bunny_accurate_position e89_send_ray(t_map *map, t_bunny_accurate_position  start, double angle)
{
  double len;
  double lon;
  double lon2;
  t_bunny_accurate_position pos;
  int winpos;
  int h;
  int w;

  h = map->height * map->tile_size;
  w = map->width * map->tile_size;
  len = 0;
  pos = e89_walk_to(start, angle, len);
  winpos = pos.y >= 0 && pos.y <= h && pos.x <= w && pos.x >= 0;
  while (winpos == 1 && map->map[(int)pos.x / map->tile_size + map->width * ((int)pos.y / map->tile_size)] != 1 && len < 270)
    {
      pos = e89_walk_to(start, angle, len);
      winpos = pos.y >= 0 && pos.y <= h && pos.x <= w && pos.x >= 0;

      if (sin(angle) < 0)
	lon = map->tile_size - (pos.y - (((int)pos.y / map->tile_size) * map->tile_size) - 1.0);
      else
	lon = pos.y - (((int)pos.y / map->tile_size) * map->tile_size) + 1.0;
      if (cos(angle) < 0)
	lon2 = pos.x - (((int)pos.x / map->tile_size) * map->tile_size) + 1.0;
      else
	lon2 = map->tile_size - (pos.x - (((int)pos.x / map->tile_size) * map->tile_size) - 1.0);
      if (lon2 == 0)
	lon2 = map->tile_size;
      if (lon == 0)
	lon = map->tile_size;
      lon2 = lon2 / std_abs(cos(angle));
      lon = lon / std_abs(sin(angle));
      if (lon2 < lon)
	lon = lon2;
      len = len + lon;
    }
  return (pos);
}

