/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** walk_to - 2021
**
** *****************************************************************************
*/

#include "runner.h"

t_bunny_accurate_position  e89_walk_to(t_bunny_accurate_position  start, double angle, double len)
{
  t_bunny_accurate_position pos;

  pos.x = cos(angle) * len + start.x;
  pos.y = -1.0 * (sin(angle) * len) + start.y;
  return (pos);
}

