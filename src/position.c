/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** position - 2021
**
** *****************************************************************************
*/

#include "runner.h"

t_bunny_position e89_position(t_bunny_accurate_position pos)
{
  t_bunny_position posi;

  posi.x = pos.x;
  posi.y = pos.y;
  return (posi);
}

