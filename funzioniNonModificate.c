#include "lib/lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/* --------------------------------------------------------------- */
/* -------------------------actor.c--------------------------------*/
/* -------------punti di ritorno multipli--------------------------*/
/* --------------------------------------------------------------- */

int fn_actor_touches_hero(fn_actor_t * actor) {
	int hero_x = hero_get_x() * FN_HALFTILE_WIDTH;
	int hero_y = hero_get_y() * FN_HALFTILE_HEIGHT;
	int hero_w = FN_TILE_WIDTH;
	int hero_h = FN_TILE_HEIGHT * 2;

	if ((hero_x + hero_w) <= (actor->x)) {
		/* hero is left of actor */
		return 0;
	}
	if ((hero_x) >= (actor->x + actor->w)) {
		/* hero is right of actor */
		return 0;
	}
	if ((hero_y + hero_h) <= (actor->y)) {
		/* hero is above actor */
		return 0;
	}
	if ((hero_y) >= (actor->y + actor->h)) {
		/* hero is below actor */
		return 0;
	}

	/* in any other case, the hero touches the actor. */
	return 1;
}
//
// /* --------------------------------------------------------------- */
// /* -------------------------actor.c--------------------------------*/
// /* -------------aggiunto default al switch-------------------------*/
// /* --------------------------------------------------------------- */
//

void fn_actor_function_item_touch_start(fn_actor_t * actor) {
        fn_hero_t * hero = fn_level_get_hero(actor->level);
        fn_actor_item_data_t * data = (fn_actor_item_data_t *) actor->data;
	int inventory = 1; //fn_hero_get_inventory(hero);
	int health = 1; //fn_hero_get_health(hero);
	int firepower = 1; //n_hero_get_firepower(hero);
	switch (actor->type) {
	case FN_ACTOR_LETTER_D:
		fn_hero_set_fetched_letter(hero, 'D');
		actor->is_alive = 0;
		fn_hero_add_score(hero, 500);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_500, actor->x, actor->y);
		break;
	case FN_ACTOR_LETTER_U:
		if (fn_hero_get_fetched_letter(hero) == 'D') {
			fn_hero_set_fetched_letter(hero, 'U');
		} else {
			fn_hero_set_fetched_letter(hero, 0);
		}
		actor->is_alive = 0;
		fn_hero_add_score(hero, 500);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_500, actor->x, actor->y);
		break;
	case FN_ACTOR_LETTER_K:
		if (fn_hero_get_fetched_letter(hero) == 'U') {
			fn_hero_set_fetched_letter(hero, 'K');
		} else {
			fn_hero_set_fetched_letter(hero, 0);
		}
		actor->is_alive = 0;
		fn_hero_add_score(hero, 500);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_500, actor->x, actor->y);
		break;
	case FN_ACTOR_LETTER_E:
		if (fn_hero_get_fetched_letter(hero) == 'K') {
			fn_hero_add_score(hero, 10000);
			////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_10000, actor->x, actor->y);
		} else {
			fn_hero_add_score(hero, 500);
			//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_500, actor->x, actor->y);
		}
		actor->is_alive = 0;
		break;
	case FN_ACTOR_FULL_LIFE:
		health = 8;
		//fn_hero_set_health(hero, health);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 1000);
		//n_level_add_actor(actor->level, FN_ACTOR_SCORE_1000, actor->x, actor->y);
		break;
	case FN_ACTOR_GUN:
		firepower++;
		fn_hero_set_firepower(hero, firepower);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 1000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_1000, actor->x, actor->y);
		break;
	case FN_ACTOR_ACCESS_CARD:
		inventory |= FN_INVENTORY_ACCESS_CARD;
		//fn_hero_set_inventory(hero, inventory);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 1000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_1000, actor->x, actor->y);
		break;
	case FN_ACTOR_GLOVE:
		inventory |= FN_INVENTORY_GLOVE;
		//fn_hero_set_inventory(hero, inventory);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 1000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_1000, actor->x, actor->y);
		break;
	case FN_ACTOR_BOOTS:
		inventory |= FN_INVENTORY_BOOT;
		//fn_hero_set_inventory(hero, inventory);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 1000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_1000, actor->x, actor->y);
		break;
	case FN_ACTOR_CLAMPS:
		inventory |= FN_INVENTORY_CLAMP;
		//fn_hero_set_inventory(hero, inventory);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 1000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_1000, actor->x, actor->y);
		break;
	case FN_ACTOR_FOOTBALL:
		fn_hero_add_score(hero, 100);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_100, actor->x, actor->y);
		actor->is_alive = 0;
		break;
	case FN_ACTOR_DISK:
		fn_hero_add_score(hero, 5000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_5000, actor->x, actor->y);
		actor->is_alive = 0;
		break;
	case FN_ACTOR_JOYSTICK:
		fn_hero_add_score(hero, 2000);
		////fn_level_add_actor(actor->level, FN_ACTOR_SCORE_2000, actor->x, actor->y);
		actor->is_alive = 0;
		break;
	case FN_ACTOR_RADIO:
	case FN_ACTOR_FLAG:
		switch (data->current_frame) {
		case 0:
			fn_hero_add_score(hero, 100);
			//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_100, actor->x, actor->y);
			break;
		case 1:
			fn_hero_add_score(hero, 2000);
			//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_2000, actor->x, actor->y);
			break;
		case 2:
			fn_hero_add_score(hero, 5000);
			//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_5000, actor->x, actor->y);
			break;
		}
		actor->is_alive = 0;
		break;
	case FN_ACTOR_SODA:
		fn_hero_improve_health(hero, 1);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 200);
		//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_200, actor->x, actor->y);
		break;
	case FN_ACTOR_CHICKEN_SINGLE:
		fn_hero_improve_health(hero, 1);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 100);
		//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_100, actor->x, actor->y);
		break;
	case FN_ACTOR_CHICKEN_DOUBLE:
		fn_hero_improve_health(hero, 2);
		actor->is_alive = 0;
		fn_hero_add_score(hero, 200);
		//fn_level_add_actor(actor->level, FN_ACTOR_SCORE_200, actor->x, actor->y);
		break;
	default:
		/* do nothing about other items */
		break;
	}
}

// /* --------------------------------------------------------------- */
// /* -------------------------actor.c--------------------------------*/
// /* -------------aggiunto else--------------------------------------*/
// /* --------------------------------------------------------------- */
//

void fn_actor_function_redball_lying_act(fn_actor_t * actor, int x) {
	fn_actor_redball_lying_data_t * data = (fn_actor_redball_lying_data_t *)actor->data; //TODO importare la struct
  fn_hero_t heroStruct = {};
	fn_hero_t * hero = &heroStruct;

	if (x) {
		actor->y += FN_HALFTILE_HEIGHT;
	}

	if (data->touching_hero == 1) {
		data->touching_hero++;
	} else if (data->touching_hero > 1) {
		//fn_hero_decrease_hurting_actors(hero, actor);
		actor->is_alive = 0;
		//fn_level_add_actor(actor->level, FN_ACTOR_FIRE, actor->x, actor->y);
	}
}

// /* --------------------------------------------------------------- */ 
// /* -------------------------actor.c--------------------------------*/
// /* -------------tolta malloc e estratto metodo updateData----------*/
// /* --------------------------------------------------------------- */

void fn_actor_function_singleanimation_create(fn_actor_t * actor) {
	fn_actor_singleanimation_data_t * data = (fn_actor_singleanimation_data_t *)malloc(sizeof(fn_actor_singleanimation_data_t));

	actor->data = data;
	actor->w = FN_TILE_WIDTH;
	actor->h = FN_TILE_HEIGHT;
	actor->is_in_foreground = 1;

	switch (actor->type) {
	case FN_ACTOR_FIRE:
		data->tile = (ANIM_BOMBFIRE);
		data->current_frame = 0;
		data->num_frames = 6;
		break;
	case FN_ACTOR_DUSTCLOUD:
		data->tile = (OBJ_DUST);
		data->current_frame = 0;
		data->num_frames = 5;
		break;
	case FN_ACTOR_STEAM:
		data->tile = (OBJ_STEAM);
		data->current_frame = 0;
		data->num_frames = 5;
		break;
	case FN_ACTOR_ROBOT_DISAPPEARING:
		data->tile = (ANIM_ROBOT) + 3;
		data->current_frame = 0;
		data->num_frames = 7;
		break;
	default:
	     data->tile=0;
		//printf(__FILE__ ":%d: warning: singleanimation #%d"
		//" added which is not a singleanimation\n", __LINE__, actor->type);
		break;
	}
}

// /* -------------------------------------------------------------- */
// /* -------------------------list.c--------------------------------*/
// /* -------------tolta malloc e tolta modifica al parametro list---*/
// /* -------------------------------------------------------------- */
/* ----------------------------------------------------------------- */

fn_list_t * fn_list_append(fn_list_t * list, void * data)
{
  fn_list_t * newitem = (fn_list_t *)malloc(sizeof(fn_list_t));
  newitem->data = data;
  newitem->next = NULL;

  fn_list_t * iter = NULL;
  fn_list_t * enditem = NULL;
  /* find the last item */
  for (iter = fn_list_first(list); iter != fn_list_last(list); iter = fn_list_next(iter))
  {
    enditem = iter;
  }

  if (enditem != NULL) {
    enditem->next = newitem;
  } else {
    list = newitem;
  }
  return list;
}

// /* --------------------------------------------------------------- */
// /* -------------------------item.c--------------------------------*/
// /* ---------tolta malloc + tolto parametro non utilizzato------------*/
// /* --------------------------------------------------------------- */

fn_item_t * fn_item_create(fn_item_type_e type,fn_level_t * level, fn_tilecache_t * tilecache, int pixelsize, int x, int y)
{
  fn_item_t * item = (fn_item_t *)malloc(sizeof(fn_item_t));

  item->type = type;
  item->tilecache = tilecache;
  item->pixelsize = pixelsize;
  item->x = x;
  item->y = y;
  item->level = level;
  item->todelete = 0;
  return item;
}

//* --------------------------------------------------------------- */
//* -------------------------item.c--------------------------------*/
// /* -------------switch ridondante + return multiplo----------------*/
// /* --------------------------------------------------------------- */

 int fn_item_act(fn_item_t * item){
    switch(item->type) {
     default:
        /* TODO */
       /* everything falls to the floor by default */
      if (!fn_level_is_solid(item->level, (item->x)/2, (item->y + 2)/2)) {
         item->y++;
       }
       break;
   }
   if (item->todelete) {
     return 0;
   } else {
     return 1;
   }
 }
// /* --------------------------------------------------------------- */
// /* -------------------------fn_actor.c--------------------------------*/
// /* ----------------------numero ciclomatico-----------------------------*/
// /* --------------------------------------------------------------- */
//

void fn_actor_function_acme_act(fn_actor_t * actor)
{
  fn_actor_acme_data_t * data = (fn_actor_acme_data_t * )actor->data;

  fn_hero_t * hero = fn_level_get_hero(actor->level);

  switch(data->counter) {
    case 0:
      {
        int xl = actor->x;
        int xr = xl + actor->w;
        int y = actor->y;
        int hxl = fn_hero_get_x(hero) * FN_HALFTILE_WIDTH;
        int hxr = hxl + FN_TILE_WIDTH;
        int hy = fn_hero_get_y(hero) * FN_HALFTILE_HEIGHT;

        if (y < hy && xl < hxr && xr > hxl) {
                        
          /* check if there are solid parts between hero and acme */
          int i = 0;
          int solidbetween = 0;
          for (i = y + FN_TILE_HEIGHT; i < hy && !solidbetween; i += FN_TILE_HEIGHT) {
            if (fn_level_is_solid(actor->level, xl / FN_TILE_WIDTH, i / FN_TILE_WIDTH) ||
                fn_level_is_solid(actor->level, xl / FN_TILE_WIDTH + 1, i / FN_TILE_WIDTH)) {

              solidbetween = 1;
            }
          }
          if (!solidbetween) {
            data->counter++;
          }
        }
      }
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
      actor->y++;
      data->counter++;
      break;
    case 2:
    case 4:
    case 6:
    case 8:
    case 10:
      actor->y--;
      data->counter++;
      break;
    default:
      if (fn_level_is_solid(actor->level,
            actor->x / FN_TILE_WIDTH,
            (actor->y / FN_TILE_HEIGHT) + 1))
      {
        fn_level_add_actor(actor->level,
            FN_ACTOR_STEAM, actor->x + FN_HALFTILE_WIDTH, actor->y);
        actor->is_alive = 0;
      } else {
        actor->y += FN_TILE_HEIGHT;
      }
      break;
  }
}

// /* --------------------------------------------------------------- */
// /* -------------------------mainmenu.c-------------------------*/
// /* ------------estratto readChoiche metodo con switch---------------*/
// /* --------------------------------------------------------------- */

 int fn_mainmenu(fn_tilecache_t * tilecache, int pixelsize, SDL_Surface * screen, int type, SDLKey key){
   SDL_Surface * msgbox;
   SDL_Surface * temp;
   SDL_Rect dstrect;
 
   int res = 0;
   int choice = 0;
   char msg[] =
     "\n"
     "  FREENUKUM MAIN MENU \n"
     "  ------------------- \n"
     "\n"
     " S)tart a new game \n"
     " R)estore an old game \n"
     " I)nstructions \n"
     " O)rdering information \n"
     " G)ame setup \n"
     " F)ullscreen toggle \n"
     " E)pisode change\n"
     " H)igh scores \n"
     " P)reviews/Main Demo! \n"
     " V)iew user demo \n"
     " T)itle screen \n"
     " C)redits \n"
     " Q)uit to DOS \n"
     "\n";
 
   SDL_Event event;
 
/*
   msgbox = fn_msgbox(pixelsize,screen->flags,screen->format,tilecache,msg);

   dstrect.x = ((screen->w)-(msgbox->w))/2;
   dstrect.y = ((screen->h)-(msgbox->h))/2;
   dstrect.w = msgbox->w;
   dstrect.h = msgbox->h;

   temp = SDL_CreateRGBSurface(screen->flags,
       dstrect.w, dstrect.h,
       screen->format->BitsPerPixel,
       0, 0, 0, 0);
   SDL_BlitSurface(screen, &dstrect, temp, NULL);

   SDL_BlitSurface(msgbox, NULL, screen, &dstrect);
   SDL_FreeSurface(msgbox);
   SDL_UpdateRect(screen, 0, 0, 0, 0);
*/
 
   while (!choice) {
     event.type = type;
     event.key.keysym.sym = key;
     switch(event.type) {
	 case SDL_KEYDOWN:
	   switch(event.key.keysym.sym) {
	     case SDLK_s:
	     case SDLK_RETURN:
	       choice = FN_MENUCHOICE_START;
	       break;
	     case SDLK_r:
	       choice = FN_MENUCHOICE_RESTORE;
	       break;
	     case SDLK_i:
	       choice = FN_MENUCHOICE_INSTRUCTIONS;
	       break;
	     case SDLK_o:
	       choice = FN_MENUCHOICE_ORDERINGINFO;
	       break;
	     case SDLK_g:
	       choice = FN_MENUCHOICE_SETUP;
	       break;
	     case SDLK_f:
	       choice = FN_MENUCHOICE_FULLSCREENTOGGLE;
	       break;
	     case SDLK_e:
	       choice = FN_MENUCHOICE_EPISODECHANGE;
	       break;
	     case SDLK_h:
	       choice = FN_MENUCHOICE_HIGHSCORES;
	       break;
	     case SDLK_p:
	       choice = FN_MENUCHOICE_PREVIEWS;
	       break;
	     case SDLK_v:
	       choice = FN_MENUCHOICE_VIEWUSERDEMO;
	       break;
	     case SDLK_t:
	       choice = FN_MENUCHOICE_TITLESCREEN;
	       break;
	     case SDLK_c:
	       choice = FN_MENUCHOICE_CREDITS;
	       break;
	     case SDLK_q:
	     case SDLK_ESCAPE:
	       choice = FN_MENUCHOICE_QUIT;
	       break;
	     default:
	       choice = -1;
	       break;
	   }
	 case SDL_VIDEOEXPOSE:
	   // SDL_UpdateRect(screen, 0, 0, 0, 0); 
           break;
	 default:
	   choice = -1;
	   break;

     }
   }
   // SDL_BlitSurface(temp, NULL, screen, &dstrect);
   // SDL_FreeSurface(temp);
   return choice;
 }
// /* --------------------------------------------------------------- */
// /* -------------------------hero.c-------------------------*/
// /* ---------numero linee codice alto (+ numero ciclomatico?)------------*/
// /* --------------------------------------------------------------- */
//

int fn_hero_act(fn_hero_t * hero, void * data)
{
  fn_level_t * lv = (fn_level_t *)data;
  int heromoved = 0;

  if (hero->immunitycountdown > 0) {
    hero->immunitycountdown--;
  }
  if (hero->immunitycountdown == 0 && hero->hurtingactors != NULL) {
    hero->immunitycountdown = hero->immunityduration;
   // fn_hero_set_health(hero, hero->health - 1);
  }

  if (lv == NULL) {
    return hero->health;
  }

  if (hero->motion == FN_HERO_MOTION_WALKING) {
    /* our hero is moving */
    switch(hero->direction) {
      case fn_horizontal_direction_left:
        if (!fn_hero_would_collide(hero, lv, hero->x-1, hero->y)) {
          hero->x--;
          heromoved = 1;
        }
        break;
      case fn_horizontal_direction_right:
        if (!fn_hero_would_collide(hero, lv, hero->x+1, hero->y)) {
          /* there is no solid block left of our hero */
          hero->x++;
          heromoved = 1;
        }
        break;
      default:
        /* do nothing else */
        break;
    }
  }

  if (hero->flying == FN_HERO_FLYING_FALSE) {
    /* our hero is standing or walking */
    hero->verticalspeed = 0;

  } else {
    /* our hero is jumping or falling */
    if (hero->counter > 0) {
      /* jumping */
      hero->counter--;
      switch(hero->counter) {
        case 3:
        case 2:
          hero->verticalspeed = 1;
          break;
        case 1:
        case 0:
          hero->verticalspeed = 0;
          break;
        default:
          hero->verticalspeed = 2;
          break;

      }

      
      int i = 0;
      for (i = 0; i < hero->verticalspeed; i++) {
        if (!fn_hero_would_collide(hero, lv, hero->x, hero->y-1)) {
          hero->y--;
          heromoved = 1;
        } else {
          /* we bumped against the ceiling */
          hero->counter = 0;
        }
      }
    } else {
      /* falling */
      if (hero->verticalspeed != 6) {
        hero->verticalspeed++;
      }

      int i = 0;
      for (i = 0; i < hero->verticalspeed/2; i++) {
        if (!fn_hero_would_collide(hero, lv, hero->x, hero->y+1)) {
          hero->y++;
          heromoved = 1;
        }
      }
    }
  }

  if (fn_hero_would_collide(hero, lv, hero->x, hero->y+1)) {
    if (hero->flying == FN_HERO_FLYING_TRUE) {
      SDL_Event event;
      event.type = SDL_USEREVENT;
      event.user.code = fn_event_herolanded;
      event.user.data1 = hero;
      event.user.data2 = 0;
     // SDL_PushEvent(&event);
    }
    /* we are standing on solid ground */
    fn_hero_set_flying(hero, FN_HERO_FLYING_FALSE);
    hero->counter = 0;
  } else {
    /* we fall down */
    if (hero->counter == 0) {
      fn_hero_set_flying(hero, FN_HERO_FLYING_TRUE);
      hero->counter = 0;
    }
  }

  if (heromoved) {
    SDL_Event event;
    event.type = SDL_USEREVENT;
    event.user.code = fn_event_heromoved;
    event.user.data1 = hero;
    event.user.data2 = 0;
   // SDL_PushEvent(&event);
  }

  return hero->health;
}

