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


int fn_actor_touches_hero(fn_actor_t * actor);
int fn_hero_get_fetched_letter(fn_hero_t * hero);
void fn_hero_set_fetched_letter(fn_hero_t * hero, int letter);
void fn_hero_set_firepower( fn_hero_t * hero, int firepower);
void fn_hero_improve_health(fn_hero_t * hero, int improvement);
void fn_hero_add_score(fn_hero_t * hero, int score);
void fn_actor_function_redball_lying_act(fn_actor_t * actor, int x);
void fn_actor_function_item_touch_start(fn_actor_t * actor);
fn_hero_t * fn_level_get_hero(fn_level_t * lv);
