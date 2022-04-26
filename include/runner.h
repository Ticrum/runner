/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** ruuner.h - 2021
**
** *****************************************************************************
*/

#include <lapin.h>
#include <time.h>

typedef struct s_mm_vertex
{
  t_bunny_accurate_position pos;
  t_bunny_position tex;
  unsigned int color;
} t_mm_vertex;

typedef struct s_mm_vertex_array
{
  size_t length;
  t_mm_vertex vertex[4000];
} t_mm_vertex_array;

typedef struct s_map
{
  int          tile_size;
  int          width;
  int          height;
  int          *map;
}              t_map;

typedef struct s_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *pix;
  t_bunny_pixelarray *pixd;
  t_bunny_accurate_position pos;
  t_bunny_picture *pict;
  t_bunny_picture *dd;
  double angle;
  t_map map;
  double vision;
  int speed;
  clock_t time;
  double fps;
  double compt;
  t_mm_vertex_array lignes;
  t_mm_vertex_array point;
}	       t_data;

#ifndef		RUNNER_H
#define		RUNNER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void		std_clear_pixelarray(t_bunny_pixelarray *pix,
				     unsigned int	color);
double		std_get_value(double	       	ratio,
			      int		min,
			      int		max);
void		e89_draw_impact(t_map		*map,
				t_bunny_pixelarray *px,
				t_bunny_accurate_position  start,
				double		angle);
t_bunny_position e89_position(t_bunny_accurate_position pos);
t_bunny_accurate_position e89_send_ray(t_map *map,
				       t_bunny_accurate_position  start,
				       double angle);
void		std_set_pixel(t_bunny_pixelarray *px,
			      t_bunny_position pos,
			      unsigned int color);
void		std_set_line(t_bunny_pixelarray *px,
			     t_bunny_position *pos,
			     unsigned int *color);
t_bunny_accurate_position  e89_walk_to(t_bunny_accurate_position  start,
				       double angle,
				       double len);
void std_set_3d(t_bunny_picture *pixd,
		t_mm_vertex_array *tab,
		t_bunny_position pos,
		int compt,
		t_bunny_position poso,
		double visu);
double std_abs(double nbr);
void std_clear_pixelarray_multiple(t_bunny_pixelarray *pix,
				   unsigned int color,
				   unsigned int color2);
double std_get_ratio(int max, int min, int curr);
double std_pow(double a, int puiss);
#endif //	RUNNER_H
