/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** clear_pixelarray_multiple - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void std_clear_pixelarray_multiple(t_bunny_pixelarray *pix, unsigned int color, unsigned int color2)
{
  int compt;
  int h;
  int w;
  unsigned int *copy;

  compt = 0;
  copy = (unsigned int *)pix->pixels;
  h = pix->clipable.buffer.height;
  w = pix->clipable.buffer.width;
  while (compt != (w * h) / 2)
    {
      copy[compt] = color;
      compt = compt + 1;
    }
  while (compt != w * h)
    {
      copy[compt] = color2;
      compt = compt + 1;
    }
}

