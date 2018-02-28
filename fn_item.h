/*******************************************************************
 *
 * Project: FreeNukum 2D Jump'n Run
 * File:    Item struct
 *
 * *****************************************************************
 *
 * Copyright 2008 Wolfgang Silbermayr
 *
 * *****************************************************************
 *
 * This file is part of Freenukum.
 * 
 * Freenukum is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Freenukum is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *******************************************************************/

#ifndef FN_ITEM_H
#define FN_ITEM_H

#include "fn_hero.h"
#include "fn_tilecache.h"

/* --------------------------------------------------------------- */

typedef enum fn_item_type_e fn_item_type_e;

/* --------------------------------------------------------------- */

typedef struct fn_item_t fn_item_t;

/* --------------------------------------------------------------- */

#include "fn_level.h"

/* --------------------------------------------------------------- */

enum fn_item_type_e {
  FN_ITEM_TYPE_BOX_GREY_EMPTY,
  FN_ITEM_TYPE_BOX_GREY_BOOTS,
  FN_ITEM_TYPE_BOX_GREY_CLAMPS,
  FN_ITEM_TYPE_BOX_GREY_GUN,
  FN_ITEM_TYPE_BOX_GREY_BOMB,
  FN_ITEM_TYPE_BOX_RED_SODA,
  FN_ITEM_TYPE_BOX_RED_CHICKEN,
  FN_ITEM_TYPE_BOX_BLUE_FOOTBALL,
  FN_ITEM_TYPE_BOX_BLUE_JOYSTICK,
  FN_ITEM_TYPE_BOX_BLUE_DISK,
  FN_ITEM_TYPE_BOX_GREY_GLOVE,
  FN_ITEM_TYPE_BOX_BLUE_BALLOON,
  FN_ITEM_TYPE_BOX_GREY_FULL_LIFE,
  FN_ITEM_TYPE_BOX_BLUE_FLAG,
  FN_ITEM_TYPE_BOX_BLUE_RADIO,
  FN_ITEM_TYPE_BOX_GREY_ACCESS_CARD,
  FN_ITEM_TYPE_BOX_GREY_D,
  FN_ITEM_TYPE_BOX_GREY_U,
  FN_ITEM_TYPE_BOX_GREY_K,
  FN_ITEM_TYPE_BOX_GREY_E,
  FN_ITEM_TYPE_FOOTBALL,
  FN_ITEM_TYPE_CHICKEN_SINGLE,
  FN_ITEM_TYPE_CHICKEN_DOUBLE,
  FN_ITEM_TYPE_SODA,
  FN_ITEM_TYPE_SODA_FLYING,
  FN_ITEM_TYPE_DISK,
  FN_ITEM_TYPE_JOYSTICK,
  FN_ITEM_TYPE_FLAG,
  FN_ITEM_TYPE_RADIO
};

/* --------------------------------------------------------------- */

struct fn_item_t {
  /**
   * The item type.
   */
  fn_item_type_e type;

  /**
   * The tilecache.
   */
  fn_tilecache_t * tilecache;

  /**
   * The size of one pixel.
   */
  int pixelsize;

  /**
   * The x position (in half-tiles)
   */
  size_t x;

  /**
   * The y position (in half-tiles)
   */
  size_t y;

  /**
   * The level inside which the item is placed.
   */
  fn_level_t * level;

  /**
   * A flag that is set true if the item should be deleted.
   */
  int todelete;
};

/* --------------------------------------------------------------- */

/**
 * Create a new item.
 *
 * @param  type  The type of the item.
 * @param  tilecache  The tilecache to use for blitting.
 * @param  x          The x position (in half-tiles)
 * @param  y          The y position (in half-tiles)
 *
 * @return  The newly created item.
 */
fn_item_t * fn_item_create(
    fn_item_type_e type,
    fn_level_t * level,
    fn_tilecache_t * tilecache,
    int pixelsize,
    size_t x,
    size_t y);

/* --------------------------------------------------------------- */

/**
 * Destroy an item.
 *
 * @param  item  The item to destroy.
 */
void fn_item_free(fn_item_t * item);

/* --------------------------------------------------------------- */

/**
 * Blit the item into the level.
 *
 * @param  item    The item to blit.
 * @param  target  The target surface.
 */
void fn_item_blit(
    fn_item_t * item,
    SDL_Surface * target);

/* --------------------------------------------------------------- */

/**
 * Calculate if the hero touches the item and take the necessary steps.
 *
 * @param  item  The item.
 * @param  hero  The hero.
 */
void fn_item_hero_check_touch(
    fn_item_t * item,
    fn_hero_t * hero);

/* --------------------------------------------------------------- */

/**
 * Get the x position of the item.
 *
 * @return The x position.
 */
size_t fn_item_get_x(fn_item_t * item);

/* --------------------------------------------------------------- */

/**
 * Get the y position of the item.
 *
 * @return The x position.
 */
size_t fn_item_get_y(fn_item_t * item);

/* --------------------------------------------------------------- */

/**
 * Act one frame.
 *
 * @param  item  The item that acts.
 *
 * @return 0 if the item is removed, otherwise non-zero. In case
 *         of 0, the caller has to remove the item using fn_item_free().
 */
int fn_item_act(fn_item_t * item);

/* --------------------------------------------------------------- */

#endif /* FN_ITEM_H */