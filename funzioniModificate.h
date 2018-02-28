struct fn_actor_t {
  int x;
  int y;
  int w;
  int h;
  void * data;
  int is_alive;
  int touches_hero;
  int is_in_foreground;
};
int fn_actor_touches_hero(fn_actor_t * actor);
