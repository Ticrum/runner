/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** draw_impact - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void  e89_draw_impact(t_map *map, t_bunny_pixelarray *px, t_bunny_accurate_position  start, double angle)
{
  t_bunny_accurate_position pos;
  //t_bunny_position posi;
  t_bunny_position start2[2];
  t_bunny_color color;

  pos = e89_send_ray(map, start, angle);
  start2[0] = e89_position(start);
  start2[1] = e89_position(pos);
  color.full = 255;
  std_set_line(px, &start2[0], &color.full);
  std_set_pixel(px, start2[1], 255);
}

