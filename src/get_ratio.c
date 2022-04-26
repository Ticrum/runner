/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** get_ratio - 2021
**
** *****************************************************************************
*/

#include "runner.h"

double std_get_ratio(int max, int min, int curr)
{
  return ((double)(curr - min) / (max - min));
}

