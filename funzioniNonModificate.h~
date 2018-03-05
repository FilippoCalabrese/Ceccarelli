#include "fn_actor.h"
#include "fn.h"

typedef struct fn_list_t fn_list_t;
typedef struct fn_level_t fn_level_t;
typedef struct fn_actor_t fn_actor_t;
typedef struct fn_hero_t fn_hero_t;
typedef enum fn_actor_type_e fn_actor_type_e;

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

struct fn_item_t {
  int pixelsize;
  int x;
  int y;
  fn_level_t * level;
  int todelete;
};

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
  //fn_list_t * hurtingactors;
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
