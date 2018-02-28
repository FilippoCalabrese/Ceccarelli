/*******************************************************************
 *
 * Project: FreeNukum 2D Jump'n Run
 * File:    Tile loader
 *
 * *****************************************************************
 *
 * Copyright 2007-2008 Wolfgang Silbermayr
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

#ifndef FN_TILE_H
#define FN_TILE_H

/* --------------------------------------------------------------- */

//#include <SDL.h>

/* --------------------------------------------------------------- */

#include "fn.h"

/* --------------------------------------------------------------- */

typedef struct {
    int tiles;
    int width;
    int height;
} fn_tileheader_t;

/* --------------------------------------------------------------- */

int fn_tile_loadheader(int fd, fn_tileheader_t * h);

/* --------------------------------------------------------------- */

SDL_Surface * fn_tile_load(
        int fd,
        int pixelsize,
        int flags,
        SDL_PixelFormat * format,
        fn_tileheader_t * h,
        int transparent_enable
        );

/* --------------------------------------------------------------- */

int fn_tile_is_solid(
    int tile);

/* --------------------------------------------------------------- */

#endif /* FN_TILE_H */