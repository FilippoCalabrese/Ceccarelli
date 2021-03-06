#include "SDL/SDL.h"

typedef struct fn_list_t fn_list_t;
typedef struct fn_level_t fn_level_t;
typedef struct fn_actor_t fn_actor_t;
typedef struct fn_hero_t fn_hero_t;


enum fn_actor_type_e {
  FN_ACTOR_FIREWHEELBOT,
  FN_ACTOR_FLAMEGNOMEBOT,
  FN_ACTOR_FLYINGBOT,
  FN_ACTOR_FOOTBOT,
  FN_ACTOR_HELICOPTERBOT,
  FN_ACTOR_RABBITOIDBOT,
  FN_ACTOR_REDBALL_JUMPING,
  FN_ACTOR_REDBALL_LYING,
  FN_ACTOR_ROBOT,
  FN_ACTOR_ROBOT_DISAPPEARING,
  FN_ACTOR_SNAKEBOT,
  FN_ACTOR_TANKBOT,
  FN_ACTOR_WALLCRAWLERBOT_LEFT,
  FN_ACTOR_WALLCRAWLERBOT_RIGHT,
  FN_ACTOR_DRPROTON,
  FN_ACTOR_CAMERA,
  FN_ACTOR_EXPLOSION,
  FN_ACTOR_FIRE,
  FN_ACTOR_DUSTCLOUD,
  FN_ACTOR_STEAM,
  FN_ACTOR_PARTICLE_PINK,
  FN_ACTOR_PARTICLE_BLUE,
  FN_ACTOR_PARTICLE_WHITE,
  FN_ACTOR_PARTICLE_GREEN,
  FN_ACTOR_ROCKET,
  FN_ACTOR_BOMB,
  FN_ACTOR_BOMBFIRE,
  FN_ACTOR_WATER,
  FN_ACTOR_EXITDOOR,
  FN_ACTOR_NOTEBOOK,
  FN_ACTOR_SURVEILLANCESCREEN,
  FN_ACTOR_HOSTILESHOT_LEFT,
  FN_ACTOR_HOSTILESHOT_RIGHT,
  FN_ACTOR_SODA,
  FN_ACTOR_SODA_FLYING,
  FN_ACTOR_UNSTABLEFLOOR,
  FN_ACTOR_EXPANDINGFLOOR,
  FN_ACTOR_CONVEYOR_LEFTMOVING_LEFTEND,
  FN_ACTOR_CONVEYOR_LEFTMOVING_RIGHTEND,
  FN_ACTOR_CONVEYOR_RIGHTMOVING_LEFTEND,
  FN_ACTOR_CONVEYOR_RIGHTMOVING_RIGHTEND,
  FN_ACTOR_FAN_LEFT,
  FN_ACTOR_FAN_RIGHT,
  FN_ACTOR_BROKENWALL_BACKGROUND,
  FN_ACTOR_STONE_BACKGROUND,
  FN_ACTOR_TELEPORTER1,
  FN_ACTOR_TELEPORTER2,
  FN_ACTOR_FENCE_BACKGROUND,
  FN_ACTOR_STONEWINDOW_BACKGROUND,
  FN_ACTOR_WINDOWLEFT_BACKGROUND,
  FN_ACTOR_WINDOWRIGHT_BACKGROUND,
  FN_ACTOR_SCREEN,
  FN_ACTOR_BOX_GREY_EMPTY,
  FN_ACTOR_BOX_GREY_BOOTS,
  FN_ACTOR_BOOTS,
  FN_ACTOR_BOX_GREY_CLAMPS,
  FN_ACTOR_CLAMPS,
  FN_ACTOR_BOX_GREY_GUN,
  FN_ACTOR_GUN,
  FN_ACTOR_BOX_GREY_BOMB,
  FN_ACTOR_BOX_RED_SODA,
  FN_ACTOR_BOX_RED_CHICKEN,
  FN_ACTOR_CHICKEN_SINGLE,
  FN_ACTOR_CHICKEN_DOUBLE,
  FN_ACTOR_BOX_BLUE_FOOTBALL,
  FN_ACTOR_FOOTBALL,
  FN_ACTOR_FLAG,
  FN_ACTOR_BOX_BLUE_JOYSTICK,
  FN_ACTOR_JOYSTICK,
  FN_ACTOR_BOX_BLUE_DISK,
  FN_ACTOR_DISK,
  FN_ACTOR_BOX_BLUE_BALLOON,
  FN_ACTOR_BALLOON,
  FN_ACTOR_BOX_GREY_GLOVE,
  FN_ACTOR_GLOVE,
  FN_ACTOR_BOX_GREY_FULL_LIFE,
  FN_ACTOR_FULL_LIFE,
  FN_ACTOR_BOX_BLUE_FLAG,
  FN_ACTOR_BLUE_FLAG,
  FN_ACTOR_BOX_BLUE_RADIO,
  FN_ACTOR_RADIO,
  FN_ACTOR_BOX_GREY_ACCESS_CARD,
  FN_ACTOR_ACCESS_CARD,
  FN_ACTOR_BOX_GREY_LETTER_D,
  FN_ACTOR_LETTER_D,
  FN_ACTOR_BOX_GREY_LETTER_U,
  FN_ACTOR_LETTER_U,
  FN_ACTOR_BOX_GREY_LETTER_K,
  FN_ACTOR_LETTER_K,
  FN_ACTOR_BOX_GREY_LETTER_E,
  FN_ACTOR_LETTER_E,
  FN_ACTOR_ACCESS_CARD_SLOT,
  FN_ACTOR_GLOVE_SLOT,
  FN_ACTOR_KEY_RED,
  FN_ACTOR_KEYHOLE_RED,
  FN_ACTOR_DOOR_RED,
  FN_ACTOR_KEY_BLUE,
  FN_ACTOR_KEYHOLE_BLUE,
  FN_ACTOR_DOOR_BLUE,
  FN_ACTOR_KEY_PINK,
  FN_ACTOR_KEYHOLE_PINK,
  FN_ACTOR_DOOR_PINK,
  FN_ACTOR_KEY_GREEN,
  FN_ACTOR_KEYHOLE_GREEN,
  FN_ACTOR_DOOR_GREEN,
  FN_ACTOR_SHOOTABLE_WALL,
  FN_ACTOR_LIFT,
  FN_ACTOR_ACME,
  FN_ACTOR_FIRE_RIGHT,
  FN_ACTOR_FIRE_LEFT,
  FN_ACTOR_MILL,
  FN_ACTOR_LASERBEAM,
  FN_ACTOR_ACCESS_CARD_DOOR,
  FN_ACTOR_SPIKES_UP,
  FN_ACTOR_SPIKES_DOWN,
  FN_ACTOR_SPIKE,
  FN_ACTOR_SCORE_100,
  FN_ACTOR_SCORE_200,
  FN_ACTOR_SCORE_500,
  FN_ACTOR_SCORE_1000,
  FN_ACTOR_SCORE_2000,
  FN_ACTOR_SCORE_5000,
  FN_ACTOR_SCORE_10000,
  FN_ACTOR_SCORE_BONUS_1_LEFT,
  FN_ACTOR_SCORE_BONUS_1_RIGHT,
  FN_ACTOR_SCORE_BONUS_2_LEFT,
  FN_ACTOR_SCORE_BONUS_2_RIGHT,
  FN_ACTOR_SCORE_BONUS_3_LEFT,
  FN_ACTOR_SCORE_BONUS_3_RIGHT,
  FN_ACTOR_SCORE_BONUS_4_LEFT,
  FN_ACTOR_SCORE_BONUS_4_RIGHT,
  FN_ACTOR_SCORE_BONUS_5_LEFT,
  FN_ACTOR_SCORE_BONUS_5_RIGHT,
  FN_ACTOR_SCORE_BONUS_6_LEFT,
  FN_ACTOR_SCORE_BONUS_6_RIGHT,
  FN_ACTOR_SCORE_BONUS_7_LEFT,
  FN_ACTOR_SCORE_BONUS_7_RIGHT,
  FN_ACTOR_BLUE_LIGHT_BACKGROUND1,
  FN_ACTOR_BLUE_LIGHT_BACKGROUND2,
  FN_ACTOR_BLUE_LIGHT_BACKGROUND3,
  FN_ACTOR_BLUE_LIGHT_BACKGROUND4,
  FN_ACTOR_TEXT_ON_SCREEN_BACKGROUND,
  FN_ACTOR_HIGH_VOLTAGE_FLASH_BACKGROUND,
  FN_ACTOR_RED_FLASHLIGHT_BACKGROUND,
  FN_ACTOR_BLUE_FLASHLIGHT_BACKGROUND,
  FN_ACTOR_KEYPANEL_BACKGROUND,
  FN_ACTOR_RED_ROTATIONLIGHT_BACKGROUND,
  FN_ACTOR_UPARROW_BACKGROUND,
  FN_ACTOR_GREEN_POISON_BACKGROUND,
  FN_ACTOR_LAVA_BACKGROUND,
  FN_ACTOR_NUM_TYPES,
};

#ifndef FN_H
#define FN_H

/* --------------------------------------------------------------- */

#define FN_DROP_WIDTH       13
#define FN_DROP_HEIGHT      10

#define FN_HALFTILE_WIDTH    8
#define FN_HALFTILE_HEIGHT   8

#define FN_FONT_WIDTH        8
#define FN_FONT_HEIGHT       8

#define FN_TILE_WIDTH       16
#define FN_TILE_HEIGHT      16

#define FN_COLOR_DEPTH       0

#define FN_WINDOW_WIDTH    320
#define FN_WINDOW_HEIGHT   200

#define FN_PICTURE_WIDTH    40
#define FN_PICTURE_HEIGHT  200

/**
 * The number of tiles how wide the level output screen is.
 */
#define FN_LEVELWINDOW_WIDTH  13

/**
 * The number of tiles how high the level output screen is.
 */
#define FN_LEVELWINDOW_HEIGHT  10

#define FN_TILECACHE_SIZE 1300

/**
 * The height of a level (in full tiles)
 */
#define FN_LEVEL_HEIGHT     90
/**
 * The width of a level (in full tiles)
 */
#define FN_LEVEL_WIDTH     128

/* --------------------------------------------------------------- */

#define FN_DEFAULT_PIXELSIZE     2
#define FN_DEFAULT_FULLSCREEN    0

/* --------------------------------------------------------------- */

#define FN_NUM_MAXLIFE       8
#define FN_SCORE_DIGITS      8
#define FN_NUM_MAXFIREPOWER  4
#define FN_SIZE_INVENTORY    8

/* --------------------------------------------------------------- */

#define FN_INVENTORY_KEY_RED     (0x01 << 7)
#define FN_INVENTORY_KEY_GREEN   (0x01 << 6)
#define FN_INVENTORY_KEY_BLUE    (0x01 << 5)
#define FN_INVENTORY_KEY_PINK    (0x01 << 4)
#define FN_INVENTORY_BOOT        (0x01 << 3)
#define FN_INVENTORY_GLOVE       (0x01 << 2)
#define FN_INVENTORY_CLAMP       (0x01 << 1)
#define FN_INVENTORY_ACCESS_CARD (0x01 << 0)

/* --------------------------------------------------------------- */

#define FNK_LEFT_ENABLED         (0x01 << 0)
#define FNK_RIGHT_ENABLED        (0x01 << 1)

/* --------------------------------------------------------------- */

typedef enum fn_horizontal_direction_e {
  fn_horizontal_direction_none,
  fn_horizontal_direction_left,
  fn_horizontal_direction_right,
  fn_horizontal_direction_size
} fn_horizontal_direction_e;

/* --------------------------------------------------------------- */

typedef enum fn_vertical_direction_e {
  fn_vertical_direction_none,
  fn_vertical_direction_up,
  fn_vertical_direction_down,
  fn_vertical_direction_size
} fn_vertical_direction_e;

/* --------------------------------------------------------------- */

typedef enum fn_event_e {
  fn_event_timer,
  fn_event_heromoved,
  fn_event_heroscored,
  fn_event_hero_firepower_changed,
  fn_event_hero_inventory_changed,
  fn_event_hero_health_changed,
  fn_event_herolanded,
} fn_event_e;

/* --------------------------------------------------------------- */

#endif /* FN_H */



struct fn_list_t {
  fn_list_t * next;
  void * data;
};

struct fn_level_t {
  fn_hero_t * hero;
  int raw[FN_LEVEL_HEIGHT][FN_LEVEL_WIDTH];
  int solid[FN_LEVEL_HEIGHT][FN_LEVEL_WIDTH];
  int tiles[FN_LEVEL_HEIGHT][FN_LEVEL_WIDTH];
  fn_list_t * actors;
  int num_shots;
  int levelpassed;
};

typedef struct fn_actor_t {
  int x;
  int y;
  int w;
  int h;
  int is_alive;
  int touches_hero;
  int is_in_foreground;
  fn_level_t * level;
  fn_actor_type_e type;
  void * data;
}fn_actor_t;

typedef struct fn_actor_redball_lying_data_t {
  int tile;
  int touching_hero;
} fn_actor_redball_lying_data_t;

typedef struct {
    SDL_Surface * tiles[FN_TILECACHE_SIZE];
    int pixelsize;
    int size;
} fn_tilecache_t;

struct fn_item_t {
  int type;
  fn_tilecache_t * tilecache;
  int pixelsize;
  int x;
  int y;
  fn_level_t * level;
  int todelete;
};


typedef struct {
    int tiles;
    int width;
    int height;
} fn_tileheader_t;

struct fn_hero_t {
  int direction;
  int motion;
  int flying;
  int shooting;
  int firepower;
  int counter;
  int tilenr;
  int animationframe;
  int num_animationframes;
  int inventory;
  int health;
  int x;
  int y;
  int score;
  int hidden;
  int fetchedletter;
  int verticalspeed;
  int immunitycountdown;
  int immunityduration;
  fn_list_t * hurtingactors;

};

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


typedef struct fn_actor_item_data_t {
  int tile;
  int current_frame;
  int num_frames;
  int standing_on_ground;
} fn_actor_item_data_t;

typedef struct fn_actor_singleanimation_data_t {
  int tile;
  int current_frame;
  int num_frames;
} fn_actor_singleanimation_data_t;

typedef struct fn_actor_acme_data_t {
  /**
   * The tile number for the tilecache.
   */
  int tile;
  /**
   * The counter for the state.
   */
  int counter;
  /**
   * A flag indicating if the hero is being touched.
   */
  int touching_hero;
} fn_actor_acme_data_t;


typedef struct fn_list_t fn_list_t;

int fn_actor_touches_hero(fn_actor_t * actor);
int fn_hero_get_fetched_letter(fn_hero_t * hero);
void fn_hero_set_fetched_letter(fn_hero_t * hero, int letter);
void fn_hero_set_firepower( fn_hero_t * hero, int firepower);
void fn_hero_improve_health(fn_hero_t * hero, int improvement);
void fn_hero_add_score(fn_hero_t * hero, int score);
void fn_actor_function_redball_lying_act(fn_actor_t * actor, int x);
void fn_actor_function_item_touch_start(fn_actor_t * actor);
fn_hero_t * fn_level_get_hero(fn_level_t * lv);
fn_list_t * fn_list_first(fn_list_t * list);
fn_list_t * fn_list_last(fn_list_t * list);
fn_list_t * fn_list_next(fn_list_t * list);
fn_list_t * fn_list_append(fn_list_t * list, void * data);
fn_item_t * fn_item_create(fn_item_type_e type,fn_level_t * level, fn_tilecache_t * tilecache, int pixelsize, int x, int y);
void fn_actor_function_singleanimation_create(fn_actor_t * actor);
int fn_level_is_solid(fn_level_t * lv, int x, int y);
int fn_item_act(fn_item_t * item);
int fn_hero_get_x(fn_hero_t * hero);
int fn_hero_get_y(fn_hero_t * hero);
int hero_get_x();
int hero_get_y();
fn_actor_t * fn_level_add_actor(fn_level_t * lv, fn_actor_type_e type, int x, int y);
void fn_actor_function_acme_act(fn_actor_t * actor);
int fn_tilecache_loadtiles();
int fn_hero_would_collide(fn_hero_t * hero, void * level,int halftile_x, int halftile_y);
void fn_hero_set_flying(fn_hero_t * hero, int flying);
int fn_hero_act(fn_hero_t * hero, void * data);
int fn_mainmenu(fn_tilecache_t * tilecache, int pixelsize, SDL_Surface * screen, int type, SDLKey key);
void updateData(fn_actor_singleanimation_data_t * data, int animation, int frame, int numFrames);
int readChoiche(int event);



#define SOLID_END                              (8 * 48)
#define ANIM_START                            SOLID_END
#define ANIM_BOMBFIRE             (ANIM_START +     90)
#define OBJ_DUST                  (OBJ_START  +     19)
#define OBJ_START                 (ANIM_START + 6 * 48)
#define OBJ_STEAM                 (OBJ_START  +     34)
#define ANIM_ROBOT                (ANIM_START +     80)
#define FN_HERO_MOTION_WALKING     1
#define FN_HERO_FLYING_FALSE       0
#define FN_HERO_FLYING_TRUE        1
#define FN_INVENTORY_BOOT        (0x01 << 3)
#define FN_HERO_MOTION_WALKING     1


#define FN_MENUCHOICE_START              1
#define FN_MENUCHOICE_RESTORE            2
#define FN_MENUCHOICE_INSTRUCTIONS       3
#define FN_MENUCHOICE_ORDERINGINFO       4
#define FN_MENUCHOICE_SETUP              5
#define FN_MENUCHOICE_FULLSCREENTOGGLE   6
#define FN_MENUCHOICE_EPISODECHANGE      7
#define FN_MENUCHOICE_HIGHSCORES         8
#define FN_MENUCHOICE_PREVIEWS           9
#define FN_MENUCHOICE_VIEWUSERDEMO      10
#define FN_MENUCHOICE_TITLESCREEN       11
#define FN_MENUCHOICE_CREDITS           12
#define FN_MENUCHOICE_QUIT              13

int switchDirection(fn_hero_t * hero, int direction, fn_level_t * lv);
void switchCounter(fn_hero_t * hero);
int elseCounter(fn_hero_t * hero,fn_level_t * lv);
void wouldCollide(fn_hero_t * hero, fn_level_t * lv);
