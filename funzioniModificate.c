#include "fn.h"
#include "funzioniModificate.h"

/* --------------------------------------------------------------- */
/* -------------------------actor.c--------------------------------*/
/* -------------punti di ritorno multipli--------------------------*/
/* --------------------------------------------------------------- */
int fn_hero_get_x(){
  return 5;
}

int fn_hero_get_y(){
  return 5;
}

int fn_actor_touches_hero(fn_actor_t * actor)
{
  int hero_x = fn_hero_get_x() * FN_HALFTILE_WIDTH;
  int hero_y = fn_hero_get_y()* FN_HALFTILE_HEIGHT;
  int hero_w = FN_TILE_WIDTH;
  int hero_h = FN_TILE_HEIGHT * 2;
  int result=-1;
  if ((hero_x + hero_w) <= (actor->x)) {
    /* hero is left of actor */
    result = 0;
  }
  else if ((hero_x) >= (actor->x + actor->w)) {
    /* hero is right of actor */
	result = 0;
  }
  else if ((hero_y + hero_h) <= (actor->y)) {
    /* hero is above actor */
	result = 0;
  }
  else if ((hero_y) >= (actor->y + actor->h)) {
    /* hero is below actor */
	result = 0;
  }
  else{
     /* in any other case, the hero touches the actor. */
     result = 1;
  }
  return result;
}

//
// /* --------------------------------------------------------------- */
// /* -------------------------actor.c--------------------------------*/
// /* -------------aggiunto default al switch-------------------------*/
// /* --------------------------------------------------------------- */
//
// void fn_actor_function_item_touch_start(fn_actor_t * actor)
// {
//   fn_hero_t * hero = fn_level_get_hero(actor->level);
//   fn_actor_item_data_t * data = (fn_actor_item_data_t *)actor->data;
//   int inventory = fn_hero_get_inventory(hero);
//   int health = fn_hero_get_health(hero);
//   int firepower = fn_hero_get_firepower(hero);
//   switch(actor->type) {
//     case FN_ACTOR_LETTER_D:
//       fn_hero_set_fetched_letter(hero, 'D');
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 500);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_500, actor->x, actor->y);
//       break;
//     case FN_ACTOR_LETTER_U:
//       if (fn_hero_get_fetched_letter(hero) == 'D') {
//         fn_hero_set_fetched_letter(hero, 'U');
//       } else {
//         fn_hero_set_fetched_letter(hero, 0);
//       }
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 500);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_500, actor->x, actor->y);
//       break;
//     case FN_ACTOR_LETTER_K:
//       if (fn_hero_get_fetched_letter(hero) == 'U') {
//         fn_hero_set_fetched_letter(hero, 'K');
//       } else {
//         fn_hero_set_fetched_letter(hero, 0);
//       }
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 500);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_500, actor->x, actor->y);
//       break;
//     case FN_ACTOR_LETTER_E:
//       if (fn_hero_get_fetched_letter(hero) == 'K') {
//       fn_hero_add_score(hero, 10000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_10000, actor->x, actor->y);
//       } else {
//       fn_hero_add_score(hero, 500);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_500, actor->x, actor->y);
//       }
//       actor->is_alive = 0;
//       break;
//     case FN_ACTOR_FULL_LIFE:
//       health = 8;
//       fn_hero_set_health(hero, health);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 1000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_1000, actor->x, actor->y);
//       break;
//     case FN_ACTOR_GUN:
//       firepower++;
//       fn_hero_set_firepower(hero, firepower);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 1000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_1000, actor->x, actor->y);
//       break;
//     case FN_ACTOR_ACCESS_CARD:
//       inventory |= FN_INVENTORY_ACCESS_CARD;
//       fn_hero_set_inventory(hero, inventory);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 1000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_1000, actor->x, actor->y);
//       break;
//     case FN_ACTOR_GLOVE:
//       inventory |= FN_INVENTORY_GLOVE;
//       fn_hero_set_inventory(hero, inventory);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 1000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_1000, actor->x, actor->y);
//       break;
//     case FN_ACTOR_BOOTS:
//       inventory |= FN_INVENTORY_BOOT;
//       fn_hero_set_inventory(hero, inventory);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 1000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_1000, actor->x, actor->y);
//       break;
//     case FN_ACTOR_CLAMPS:
//       inventory |= FN_INVENTORY_CLAMP;
//       fn_hero_set_inventory(hero, inventory);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 1000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_1000, actor->x, actor->y);
//       break;
//     case FN_ACTOR_FOOTBALL:
//       fn_hero_add_score(hero, 100);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_100, actor->x, actor->y);
//       actor->is_alive = 0;
//       break;
//     case FN_ACTOR_DISK:
//       fn_hero_add_score(hero, 5000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_5000, actor->x, actor->y);
//       actor->is_alive = 0;
//       break;
//     case FN_ACTOR_JOYSTICK:
//       fn_hero_add_score(hero, 2000);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_2000, actor->x, actor->y);
//       actor->is_alive = 0;
//       break;
//     case FN_ACTOR_RADIO:
//     case FN_ACTOR_FLAG:
//       switch(data->current_frame) {
//         case 0:
//           fn_hero_add_score(hero, 100);
//           fn_level_add_actor(actor->level,
//               FN_ACTOR_SCORE_100, actor->x, actor->y);
//           break;
//         case 1:
//           fn_hero_add_score(hero, 2000);
//           fn_level_add_actor(actor->level,
//               FN_ACTOR_SCORE_2000, actor->x, actor->y);
//           break;
//         case 2:
//           fn_hero_add_score(hero, 5000);
//           fn_level_add_actor(actor->level,
//               FN_ACTOR_SCORE_5000, actor->x, actor->y);
//           break;
//         default:
//         	/* do nothing*/
//         	break;
//       }
//       actor->is_alive = 0;
//       break;
//     case FN_ACTOR_SODA:
//       fn_hero_improve_health(hero, 1);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 200);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_200, actor->x, actor->y);
//       break;
//     case FN_ACTOR_CHICKEN_SINGLE:
//       fn_hero_improve_health(hero, 1);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 100);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_100, actor->x, actor->y);
//       break;
//     case FN_ACTOR_CHICKEN_DOUBLE:
//       fn_hero_improve_health(hero, 2);
//       actor->is_alive = 0;
//       fn_hero_add_score(hero, 200);
//       fn_level_add_actor(actor->level,
//           FN_ACTOR_SCORE_200, actor->x, actor->y);
//       break;
//     default:
//     	/* do nothing about other items */
//     	break;
//   }
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------actor.c--------------------------------*/
// /* -------------aggiunto else--------------------------------------*/
// /* --------------------------------------------------------------- */
//
// void fn_actor_function_redball_lying_act(
//     fn_actor_t * actor)
// {
//   fn_actor_redball_lying_data_t * data = actor->data;
//   fn_hero_t * hero = fn_level_get_hero(actor->level);
//
//   if (!fn_level_is_solid(actor->level,
//         (actor->x) / FN_TILE_WIDTH,
//         (actor->y) / FN_TILE_HEIGHT + 1)) {
//     actor->y += FN_HALFTILE_HEIGHT;
//   }
//
//   if (data->touching_hero == 1) {
//     data->touching_hero++;
//   } else if (data->touching_hero > 1) {
//     fn_hero_decrease_hurting_actors(hero, actor);
//     actor->is_alive = 0;
//     fn_level_add_actor(actor->level,
//         FN_ACTOR_FIRE, actor->x, actor->y);
//   }else{
// 	//Nothing to do
//   }
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------actor.c--------------------------------*/
// /* -------------tolta malloc e estratto metodo updateData-------------------------*/
// /* --------------------------------------------------------------- */
//
// void fn_actor_function_singleanimation_create(fn_actor_t * actor)
// {
//   fn_actor_singleanimation_data_t dataStruct = {0, 0, 0};
//
//   actor->data = dataStruct;
//   actor->w = FN_TILE_WIDTH;
//   actor->h = FN_TILE_HEIGHT;
//   actor->is_in_foreground = 1;
//
//   fn_actor_singleanimation_data_t * data = &dataStruct;
//
//   switch(actor->type) {
//     case FN_ACTOR_FIRE:
//       updateData(data, ANIM_BOMBFIRE, 0, 6);
//       break;
//     case FN_ACTOR_DUSTCLOUD:
//       updateData(data, OBJ_DUST, 0, 5);
//       break;
//     case FN_ACTOR_STEAM:
//       updateData(data, OBJ_STEAM, 0, 5);
//       break;
//     case FN_ACTOR_ROBOT_DISAPPEARING:
//       updateData(data, ANIM_ROBOT+3, 0, 7);
//
//       break;
//     default:
//       printf(__FILE__ ":%d: warning: singleanimation #%d"
//           " added which is not a singleanimation\n",
//           __LINE__, actor->type);
//       break;
//   }
// }
//
// void updateData(fn_actor_singleanimation_data_t * data, int animation, int frame, int numFrames){
//   data->tile = animation;
//   data->current_frame = frame;
//   data->num_frames = numFrames;
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------list.c--------------------------------*/
// /* -------------tolta malloc e tolta modifica al parametro list----------------------*/
// /* --------------------------------------------------------------- */
//
// fn_list_t * fn_list_append(fn_list_t * list,
//     void * data)
// {
//
//   fn_list_t l = {NULL, data};
//   fn_list_t * newitem = &l;
//
//   fn_list_t * iter = NULL;
//   fn_list_t * enditem = NULL;
//   /* find the last item */
//   for (iter = fn_list_first(list); iter != fn_list_last(list); iter = fn_list_next(iter))
//   {
//     enditem = iter;
//   }
//
//   fn_list_t * result = list;
//   if (enditem != NULL) {
//     enditem->next = newitem;
//   } else {
//     result = newitem;
//   }
//   return result;
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------item.c--------------------------------*/
// /* ----------------------tolta malloc-----------------------------*/
// /* --------------------------------------------------------------- */
//
// fn_item_t * fn_item_create(
//     fn_item_type_e type,
//     fn_level_t * level,
//     fn_tilecache_t * tilecache,
//     int pixelsize,
//     size_t x,
//     size_t y)
// {
//   struct fn_item_t itemStruct;
//   struct fn_item_t *item;
//
//   item=&itemStruct;
//
//   itemStruct.type = type;
//   itemStruct.tilecache = tilecache;
//   itemStruct.pixelsize = pixelsize;
//   itemStruct.x = x;
//   itemStruct.y = y;
//   itemStruct.level = level;
//   itemStruct.todelete = 0;
//   return item;
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------item.c--------------------------------*/
// /* -------------switch ridondante + return multiplo----------------*/
// /* --------------------------------------------------------------- */
// int fn_item_act(fn_item_t * item)
// {
// int result = -1;
//   /* everything falls to the floor by default */
//   if (!fn_level_is_solid((*item).level, ((*item).x)/2, ((*item).y + 2)/2)) {
//      (*item).y++;
//   }else{}
//   if ((*item).todelete) {
//      result = 0;
//   } else {
//     result = 1;
//   }
//   return result;
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------picture_splash.c--------------------------------*/
// /* ----------------------return + break-----------------------------*/
// /* --------------------------------------------------------------- */
//
// int fn_picture_splash_show_with_message(char * datapath,
//     char * filename,
//     int pixelsize,
//     SDL_Surface * screen,
//     fn_tilecache_t * tilecache,
//     char * msg,
//     int x,
//     int y)
// {
//   char * path;
//   int fd;
//   int res;
//   SDL_Event event;
//   SDL_Surface * picture;
//
//   path = malloc(strlen(datapath) + strlen(filename) + 1);
//   sprintf(path, "%s%s", datapath, filename);
//   fd = open(path, O_RDONLY);
//
//   if (fd == -1) {
//     fn_error_printf(1024, "Could not open file %s for reading: %s",
//         path,strerror(errno));
//     free(path);
//     return 0;
//   }
//   free(path);
//
//   int flags = screen->flags;
//
//   picture = fn_picture_load(fd, pixelsize, flags, screen->format);
//
//   SDL_BlitSurface(picture, NULL, screen, NULL);
//
//
//   if (tilecache != NULL && msg != NULL) {
//     SDL_Surface * msgbox;
//     SDL_Rect dstrect;
//
//     msgbox = fn_msgbox(pixelsize,
//         screen->flags,
//         screen->format,
//         tilecache,
//         msg);
//
//     dstrect.x = x * pixelsize;
//     dstrect.y = y * pixelsize;
//
//     SDL_BlitSurface(msgbox, NULL, screen, &dstrect);
//     SDL_FreeSurface(msgbox);
//   }
//
//   SDL_UpdateRect(screen, 0, 0, 0, 0);
//   SDL_FreeSurface(picture);
//
//   int result=0;
//   while (result==0) {
//     res = SDL_WaitEvent(&event);
//     if (res == 1) {
//       switch(event.type) {
//         case SDL_QUIT:
//           result=1;
//           break;
//         case SDL_KEYDOWN:
//           switch(event.key.keysym.sym) {
//             case SDLK_ESCAPE:
//             case SDLK_RETURN:
//                 result=1;
//             default:
//               /* ignore other keys */
//               break;
//           }
//         case SDL_VIDEOEXPOSE:
//           SDL_UpdateRect(screen, 0, 0, 0, 0);
//           break;
//         default:
//           /* ignore unknown events */
//           break;
//       }
//     }
//   }
//   return result;
// }
//
// /* --------------------------------------------------------------- */
// /* -------------------------mainmenu.c-------------------------*/
// /* ------------estratto readChoiche metodo con switch---------------*/
// /* --------------------------------------------------------------- */
//
// int fn_mainmenu(fn_tilecache_t * tilecache,
//     int pixelsize,
//     SDL_Surface * screen)
// {
//   SDL_Surface * msgbox;
//   SDL_Surface * temp;
//   SDL_Rect dstrect;
//
//   int res = 0;
//   int choice = 0;
//   char * msg =
//     "\n"
//     "  FREENUKUM MAIN MENU \n"
//     "  ------------------- \n"
//     "\n"
//     " S)tart a new game \n"
//     " R)estore an old game \n"
//     " I)nstructions \n"
//     " O)rdering information \n"
//     " G)ame setup \n"
//     " F)ullscreen toggle \n"
//     " E)pisode change\n"
//     " H)igh scores \n"
//     " P)reviews/Main Demo! \n"
//     " V)iew user demo \n"
//     " T)itle screen \n"
//     " C)redits \n"
//     " Q)uit to DOS \n"
//     "\n";
//
//   SDL_Event event;
//
//   msgbox = fn_msgbox(pixelsize,
//       screen->flags,
//       screen->format,
//       tilecache,
//       msg);
//
//   dstrect.x = ((screen->w)-(msgbox->w))/2;
//   dstrect.y = ((screen->h)-(msgbox->h))/2;
//   dstrect.w = msgbox->w;
//   dstrect.h = msgbox->h;
//
//   temp = SDL_CreateRGBSurface(screen->flags,
//       dstrect.w, dstrect.h,
//       screen->format->BitsPerPixel,
//       0, 0, 0, 0);
//   SDL_BlitSurface(screen, &dstrect, temp, NULL);
//
//   SDL_BlitSurface(msgbox, NULL, screen, &dstrect);
//   SDL_FreeSurface(msgbox);
//   SDL_UpdateRect(screen, 0, 0, 0, 0);
//
//   while (!choice) {
//     res = SDL_WaitEvent(&event);
//     if (res == 1) {
//       switch(event.type) {
//         case SDL_KEYDOWN:
//           choice = readChoiche(event.key.keysym.sym);
//           break;
//         case SDL_VIDEOEXPOSE:
//           SDL_UpdateRect(screen, 0, 0, 0, 0);
//           break;
//         default:
//           /* ignore other events */
//           break;
//       }
//     }
//   }
//   SDL_BlitSurface(temp, NULL, screen, &dstrect);
//   SDL_FreeSurface(temp);
//   return choice;
// }
//
// int readChoiche(int event){
//   int choice = 0;
//   switch(event.key.keysym.sym) {
//     case SDLK_s:
//     case SDLK_RETURN:
//       choice = FN_MENUCHOICE_START;
//       break;
//     case SDLK_r:
//       choice = FN_MENUCHOICE_RESTORE;
//       break;
//     case SDLK_i:
//       choice = FN_MENUCHOICE_INSTRUCTIONS;
//       break;
//     case SDLK_o:
//       choice = FN_MENUCHOICE_ORDERINGINFO;
//       break;
//     case SDLK_g:
//       choice = FN_MENUCHOICE_SETUP;
//       break;
//     case SDLK_f:
//       choice = FN_MENUCHOICE_FULLSCREENTOGGLE;
//       break;
//     case SDLK_e:
//       choice = FN_MENUCHOICE_EPISODECHANGE;
//       break;
//     case SDLK_h:
//       choice = FN_MENUCHOICE_HIGHSCORES;
//       break;
//     case SDLK_p:
//       choice = FN_MENUCHOICE_PREVIEWS;
//       break;
//     case SDLK_v:
//       choice = FN_MENUCHOICE_VIEWUSERDEMO;
//       break;
//     case SDLK_t:
//       choice = FN_MENUCHOICE_TITLESCREEN;
//       break;
//     case SDLK_c:
//       choice = FN_MENUCHOICE_CREDITS;
//       break;
//     case SDLK_q:
//     case SDLK_ESCAPE:
//       choice = FN_MENUCHOICE_QUIT;
//       break;
//     default:
//       /* ignore other input */
//       break;
//
//     return choice;
//   }
// }