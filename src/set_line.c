/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** set_line - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void std_set_line(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int *color)
{
  float ratio;
  t_bunny_position posi;
  float up;

  ratio = 0;
  //up = 1 / (float)(sqrt((std_abs(pos[1].x - pos[0].x) * std_abs(pos[1].x -
  //pos[0].x)) + (std_abs(pos[1].y - pos[0].y) * std_abs(pos[1].y - pos[0].y)))
  //+ 5);
  up = 1.0 / (float)pos[1].y - pos[0].y;
  while (ratio <= 1)
      {
          posi.x = pos[0].x;//std_get_value(ratio, pos[0].x, pos[1].x);
          posi.y = std_get_value(ratio, pos[0].y, pos[1].y);
          std_set_pixel(px, posi, color[0]);
          ratio = ratio + up;
      }
}

