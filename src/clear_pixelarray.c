/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** clear_pixelarray - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void std_clear_pixelarray(t_bunny_pixelarray *pix, unsigned int color)
{
  int compt;
  int *copy;
  int h;
  int w;

  compt = 0;
  copy = (int *)pix->pixels;
  h = pix->clipable.buffer.height;
  w = pix->clipable.buffer.width;
  while (compt != w * h)
    {
      copy[compt] = color;
      compt = compt + 1;
    }
}

