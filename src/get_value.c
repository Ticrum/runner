/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** get_value - 2021
**
** *****************************************************************************
*/

#include "runner.h"

double  std_get_value(double ratio, int min, int max)
{
  return ((double)min + (ratio * (max - min)));
}

