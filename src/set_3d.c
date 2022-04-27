/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** set_3d - 2021
**
** *****************************************************************************
*/

#include "runner.h"
void std_set_3d(t_bunny_picture *pixd, t_mm_vertex_array *tab, t_bunny_position pos, int compt, t_bunny_position poso, double visu)
{
  t_bunny_accurate_position posi[2];
  double dist;
  unsigned int color[1];
  double angle;
  double distance;
  int max;
  double ratio;
  t_bunny_color colori;

  max = 200;
  distance = sqrt(std_abs(poso.x - pos.x) * std_abs(poso.x - pos.x) + std_abs(poso.y - pos.y) * std_abs(poso.y - pos.y));
  angle = visu - compt * ((double)(visu * 2) / pixd->buffer.width);
  distance = distance * cos(angle);
  ratio = std_get_ratio(max, 0, distance);
  if (ratio > 1)
    ratio = 1;
  colori.full = RED;
  colori.argb[RED_CMP] = std_get_value(1 - ratio, 0, 255);
  colori.argb[ALPHA_CMP] = 255;
  color[0] = colori.full;
  dist = ((200 * ((pixd->buffer.height / 4) / distance)) / 4);
  if (dist > pixd->buffer.height / 1.95)
    dist = pixd->buffer.height / 1.95;
  if (dist < 10)
    dist = 10;
  posi[0].x = compt;
  posi[0].y = pixd->buffer.height / 2 - dist;
  posi[1].x = compt;
  posi[1].y = pixd->buffer.height / 2 + dist;
  tab->vertex[compt * 2].pos = posi[0];
  tab->vertex[compt * 2].color = color[0];
  tab->vertex[compt * 2 + 1].pos = posi[1];
  tab->vertex[compt * 2 + 1].color = color[0];
}

