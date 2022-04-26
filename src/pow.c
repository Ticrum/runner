/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** pow - 2021
**
** *****************************************************************************
*/

#include "runner.h"

double std_pow(double a, int puiss)
{
  int compteur;
  double mult;

  mult = 1;
  compteur = 0;
  while (compteur != puiss)
    {
      mult = mult * a;
      compteur = compteur + 1;
    }
  return (mult);
}

