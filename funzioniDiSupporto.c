#include "lib/lib.h"
#include <stdio.h>
#include <stdlib.h>

int hero_get_x(){
  return 5;
}

int hero_get_y(){
  return 5;
}

int fn_hero_get_fetched_letter(fn_hero_t * hero)
{
  return hero->fetchedletter;
}

fn_hero_t * fn_level_get_hero(fn_level_t * lv) {
  return lv->hero;
}

void fn_hero_set_fetched_letter(fn_hero_t * hero, int letter)
{
  hero->fetchedletter = letter;
}

void fn_hero_set_firepower( fn_hero_t * hero, int firepower) {
  if (firepower > 4) {
    firepower = 4;
  }
  hero->firepower = firepower;
}

void fn_hero_improve_health(fn_hero_t * hero, int improvement){
  hero->health+=improvement;
}

void fn_hero_add_score(fn_hero_t * hero, int score) {
  hero->score+=score;
}

fn_list_t * fn_list_first(fn_list_t * list)
{
  return list;
}

fn_list_t * fn_list_last(fn_list_t * list)
{
  return NULL;
}

fn_list_t * fn_list_next(fn_list_t * list)
{
  if (list != NULL) {
    return list->next;
  }
  return NULL;
}

int fn_level_is_solid(fn_level_t * lv, int x, int y)
{
  if (x < 0 || y < 0 || x > FN_LEVEL_WIDTH || y > FN_LEVEL_HEIGHT) {
    return 1;
  }
  return lv->solid[y][x];
}

int fn_hero_get_x(fn_hero_t * hero)
{
  return hero->x;
}

int fn_hero_get_y(fn_hero_t * hero)
{
  return hero->y;
}

fn_actor_t * fn_level_add_actor(fn_level_t * lv, fn_actor_type_e type, int x, int y)
{
  fn_actor_t actorStruct={};
  fn_actor_t * actor = &actorStruct;

  actor->level = lv;
  actor->type = type;
  actor->x = x;
  actor->y = y;
  actor->w = 0; 
  actor->h = 0; 
  actor->is_alive = 1;
  actor->touches_hero = 0;
  actor->is_in_foreground = 0;

  lv->actors = fn_list_append(lv->actors, actor);
  return actor;
}

int fn_hero_would_collide(fn_hero_t * hero, void * level,
    int halftile_x, int halftile_y)
{
  fn_level_t * lv = (fn_level_t *)level;
  if (lv == NULL) {
    return 1;
  }
  if (halftile_x < 0 || halftile_x > FN_LEVEL_WIDTH * 2 ||
      halftile_y < 0 || halftile_y > FN_LEVEL_HEIGHT * 2) {
    return 1;
  }
  int i = 0;
  int j = 0;

  for (i = halftile_x; i < halftile_x + 2; i++) {
    for (j = halftile_y-2; j < halftile_y+2; j++) {
      if (fn_level_is_solid(lv, i/2, j/2)) {
        return 1;
      }
    }
  }

  return 0;
}

void fn_hero_set_flying(
    fn_hero_t * hero,
    int flying)
{
  if (flying == FN_HERO_FLYING_TRUE) {
    if (hero->flying != flying) {
      if (hero->inventory & FN_INVENTORY_BOOT) {
        hero->counter = 7;
        hero->verticalspeed = 2;
      } else {
        hero->counter = 6;
        hero->verticalspeed = 2;
      }
    }
  }
  hero->flying = flying;
}
