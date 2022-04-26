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
  //double val;
  int max;
  double ratio;
  //double p;
  t_bunny_color colori;

  max = 200;//220000
  distance = sqrt(std_abs(poso.x - pos.x) * std_abs(poso.x - pos.x) + std_abs(poso.y - pos.y) * std_abs(poso.y - pos.y));
  angle = visu - compt * ((double)(visu * 2) / pixd->buffer.width);
  //distance = distance * cos(angle);//* (distance / 100);
  //printf("OO%fOO", p);
  //distance = p / (p + distance);
  //printf("$$%f$$", distance);
  distance = distance * cos(angle);
  //val = 1000 - distance;
  //if (val < 0)
  //val = 0;
  //distance = distance - pow(val / 100, 3);
  //printf("{%f ",distance);
  //distance =1 + log(distance) / 2;
  //printf("%f}\n",distance);
  //distance = distance * 100;
  //write(1,"a",1);
  ratio = std_get_ratio(max, 0, distance);
  if (ratio > 1)
    ratio = 1;
  colori.full = RED;
  colori.argb[RED_CMP] = std_get_value(1 - ratio, 0, 255);
  colori.argb[ALPHA_CMP] = 255;
  color[0] = colori.full;
  //dist = pixd->clipable.buffer.height / 2 - ((0.7 * ((pixd->clipable.buffer.height / 2) / (double)300)) * (distance * cos(angle)))/*- std_abs(30 * (1 - cos(angle) * cos(angle) * cos(angle)))*/;
  //ratio = distance;
  //printf("%f\n",ratio);
  //angle = std_get_value(ratio, 0, M_PI / 2);
  dist = ((200 * ((pixd->buffer.height / 4) / distance)) / 4);
  //printf("/%f %d %f/", (double)dist * cos(angle), dist, angle);
  //dist = std_get_value(ratio, 0, pixd->clipable.buffer.height / 2);
  //dist = /*(double)dist*/(1 - (sin(angle)) /*+ sin(M_PI / 2 - angle)*/) /*std_get_value(1 - ratio, 0, 200)*/;
  //printf("%f ''\n",dist);d
  //dist = exp(dist);
  /*
  dist = dist * dist;// / 200;
  dist = dist * dist;// / 190;
  dist = dist * dist;// / 200;
  dist = dist * dist;// / 210;
  dist = dist * dist;// / 180;
  dist = dist * dist;
  dist = dist * dist;
  dist = dist * dist;
  dist = dist * dist;
  dist = dist * dist;
  dist = dist * dist;
  */
  //printf("%f\n",dist);
  //printf("%f //\n",dist);
  //printf("/%f %d/",angle,dist);
  //printf("!!%f!!",dist);
  //if (dist > pixd->clipable.buffer.height / 6)
  //dist = dist + pow(dist / 68, 15) / 30000;
  //dist = dist / 2;
  if (dist > pixd->buffer.height / 1.95)
    dist = pixd->buffer.height / 1.95;
  if (dist < 10)
    dist = 10;
  //printf("!!%f!!",dist);
  //write(1,"a",1);
  posi[0].x = compt;
  //write(1,"a",1);
  posi[0].y = pixd->buffer.height / 2 - dist;
  //write(1,"a",1);
  posi[1].x = compt;
  posi[1].y = pixd->buffer.height / 2 + dist;
  //write(1,"a",1);
  //std_set_line(pixd, &posi[0], color);
  tab->vertex[compt * 2].pos = posi[0];
  tab->vertex[compt * 2].color = color[0];
  tab->vertex[compt * 2 + 1].pos = posi[1];
  tab->vertex[compt * 2 + 1].color = color[0];
  //bunny_set_line(&pixd->buffer, &posi[0], color);
  //write(1,"a",1);
}

