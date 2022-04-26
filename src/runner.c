/*
** *****************************************************************************
** thomas.barbe
** thomas.barbe <thomas.barbe@student-station>
**
** runner.c - 2021
**
** *****************************************************************************
*/

#include "runner.h"

static t_bunny_response color_rand(t_bunny_event_state state, t_bunny_keysym keycode, void *data)
{
  t_data *data2;

  data2 = (t_data *)data;
  if (state == GO_UP)
    return (GO_ON);
  if (keycode == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (keycode == BKS_O)
    std_clear_pixelarray(data2->pix, RED);
  if (keycode == BKS_U)
    std_clear_pixelarray(data2->pix, BLUE);
  return (GO_ON);
}

static t_bunny_response display(void *data)
{
  t_data *data2;
  t_bunny_accurate_position posi;
  double angle2;
  int compt;
  t_bunny_position decal[1];
  double part;
  double fps;

  decal[0].x = 600;
  decal[0].y = 0;
  data2 = (t_data *)data;
  bunny_clear(&data2->dd->buffer, BLACK);
  data2->point.vertex[0].pos = data2->pos;
  data2->point.vertex[0].color = GREEN;
  posi = e89_walk_to(data2->pos, data2->angle, 50);
  data2->point.vertex[1].pos = posi;
  data2->point.vertex[1].color = RED;
  angle2 = data2->angle + data2->vision;
  compt = 1;
  part = (double)(data2->vision * 2) / (data2->pict->buffer.width);
  while (angle2 > data2->angle - (data2->vision - part))
    {
      posi = e89_send_ray(&data2->map, data2->pos, angle2);
      std_set_3d(data2->pict, &data2->lignes, e89_position(posi), compt, e89_position(data2->pos), data2->vision);
      data2->point.vertex[1 + compt].pos = posi;
      data2->point.vertex[1 + compt].color = BLUE;
      angle2 = angle2 - part;
      compt = compt + 1;
    }
  bunny_set_geometry(&data2->pict->buffer, BGY_LINES, (t_bunny_vertex_array *)&data2->lignes, NULL);
  bunny_set_geometry(&data2->dd->buffer, BGY_PIXELS, (t_bunny_vertex_array *)&data2->point, NULL);
  bunny_blit(&data2->win->buffer, data2->dd, NULL);
  bunny_blit(&data2->win->buffer, data2->pict, &decal[0]);
  bunny_display(data2->win);
  fps = 1.0 / ((double)(clock() - data2->time) / CLOCKS_PER_SEC);
  data2->fps = data2->fps + fps;
  data2->compt = data2->compt + 1;
  if ((int)clock() % CLOCKS_PER_SEC > 960000)
    printf("FPS = %f Avr = %f\n",fps, data2->fps / data2->compt);
  return (GO_ON);
}

static t_bunny_response test(void *data)
{
  t_data *data2;
  int sped;

  data2 = (t_data *)data;
  data2->time = clock();
  bunny_clear(&data2->pict->buffer, BLACK);
  sped = data2->speed;
  bunny_set_key_repeat(data2->win, true);
  if (bunny_get_keyboard()[BKS_Z])
    {
      if (bunny_get_keyboard()[BKS_LSHIFT])
	sped = data2->speed * 2;
      else
	sped = data2->speed;
      data2->pos = e89_walk_to(data2->pos, data2->angle, sped);
    if (data2->map.map[(int)data2->pos.x / data2->map.tile_size + data2->map.width * ((int)data2->pos.y / data2->map.tile_size)] == 1)
      data2->pos = e89_walk_to(data2->pos, data2->angle, -sped);
    }
  if (bunny_get_keyboard()[BKS_S])
    {
      data2->pos = e89_walk_to(data2->pos, data2->angle - M_PI, sped);
      if (data2->map.map[(int)data2->pos.x / data2->map.tile_size + data2->map.width * ((int)data2->pos.y / data2->map.tile_size)] == 1)
	  data2->pos = e89_walk_to(data2->pos, data2->angle - M_PI, -sped);
    }
  if (bunny_get_keyboard()[BKS_Q])
    {
    data2->pos = e89_walk_to(data2->pos, data2->angle + M_PI / 2, sped);
    if (data2->map.map[(int)data2->pos.x / data2->map.tile_size + data2->map.width * ((int)data2->pos.y / data2->map.tile_size)] == 1)
      data2->pos = e89_walk_to(data2->pos, data2->angle + M_PI / 2, -sped);
    }
  if (bunny_get_keyboard()[BKS_D])
    {
      data2->pos = e89_walk_to(data2->pos, data2->angle - M_PI / 2, sped);
      if (data2->map.map[(int)data2->pos.x / data2->map.tile_size + data2->map.width * ((int)data2->pos.y / data2->map.tile_size)] == 1)
	data2->pos = e89_walk_to(data2->pos, data2->angle - M_PI / 2, -sped);
    }
  if (bunny_get_keyboard()[BKS_A])
    data2->angle = data2->angle + M_PI / 60;
  if (bunny_get_keyboard()[BKS_E])
    data2->angle = data2->angle - M_PI / 60;
  return(GO_ON);
}

int main(void)
{
  t_data data;

  int mx[20 * 20] = {
    1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1
};
  data.win = bunny_start(1900, 1000, false,"Bunny");
  data.pix = bunny_new_pixelarray(600, 600);
  data.pixd = bunny_new_pixelarray(600, 400);
  data.pict = bunny_new_picture(1300, 1000);
  data.dd = bunny_new_picture(600, 600);
  data.lignes.length = 2600;
  data.point.length = 1305;
  data.pos.x = 120;
  data.pos.y = 120;
  data.angle = 0;
  data.vision = 0.7;
  data.speed = 1;
  data.time = 0;
  data.fps = 0;
  data.compt = 0;
  data.map.map = &mx[0];
  data.map.width = 20;
  data.map.height = 20;
  data.map.tile_size = data.pix->clipable.buffer.width / data.map.width;
  bunny_set_key_response(color_rand);
  bunny_set_display_function(display);
  bunny_set_loop_main_function(test);
  bunny_display(data.win);
  bunny_loop(data.win, 60, &data);
  bunny_stop(data.win);
  return (EXIT_SUCCESS);
}

