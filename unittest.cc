#include <limits.h>
#include "lib/lib.h"
#include "gtest/gtest.h"
namespace {

//TEST fn_actor_touches_hero

  TEST(unit_test, testTouchesLeft){
    fn_actor_t actor = {
      100, 100, 1, 1, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(unit_test, testTouchesRight){
    fn_actor_t actor = {
      1, 1, 1, 1, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(unit_test, testTouchesAbove){
    fn_actor_t actor = {
      1, 100, 1000, 1, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(unit_test, testTouchesBelow){
    fn_actor_t actor = {
      1, 1, 100, 20, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(unit_test, testTouchesOther){
    fn_actor_t actor = {
      1, 1, 1000, 1000, 1, 1, 1
    };
    EXPECT_EQ(1, fn_actor_touches_hero(&actor));
  }

// TEST fn_actor_function_redball_lying_act

  TEST(unit_test, testRedballLyingWithTrueValue){

    //inizializzazione delle strutture necessarie
    fn_actor_redball_lying_data_t dataStruct = {
      1, 1
    };
    fn_actor_redball_lying_data_t * data = &dataStruct;
    fn_actor_t actorStruct = {};
    actorStruct.data = data;
    fn_actor_t * actor = &actorStruct;

    //prima chiamata al metodo e verifica del valore risultante nei vari campi
    fn_actor_function_redball_lying_act(actor, 1);
    int res = actorStruct.y;
    EXPECT_EQ(8, res);
    res = dataStruct.touching_hero;
    EXPECT_EQ(2, res);

    //chiama il metodo una seconda volta e verifica i valori risultanti
    fn_actor_function_redball_lying_act(actor, 1);
    res = actorStruct.y;
    EXPECT_EQ(16, res);
    res = dataStruct.touching_hero;
    EXPECT_EQ(2, res);
    res = actorStruct.is_alive;
    EXPECT_EQ(0, res);

  }


  TEST(unit_test, testRedballLyingWithFalseValue){

    //inizializzazione delle strutture necessarie
    fn_actor_redball_lying_data_t dataStruct = {
      1, 1
    };
    fn_actor_redball_lying_data_t * data = &dataStruct;
    fn_actor_t actorStruct = {};
    actorStruct.data = data;
    fn_actor_t * actor = &actorStruct;

    //prima chiamata al metodo e verifica del valore risultante nei vari campi
    fn_actor_function_redball_lying_act(actor, 0);
    int res = actorStruct.y;
    EXPECT_EQ(0, res);
    res = dataStruct.touching_hero;
    EXPECT_EQ(2, res);

    //chiama il metodo una seconda volta e verifica i valori risultanti
    fn_actor_function_redball_lying_act(actor, 0);
    res = actorStruct.y;
    EXPECT_EQ(0, res);
    res = dataStruct.touching_hero;
    EXPECT_EQ(2, res);
    res = actorStruct.is_alive;
    EXPECT_EQ(0, res);

  }

//TEST fn_actor_function_item_touch_start

  TEST(unit_test, itemTouchStartLetterD){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_D;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_item_touch_start(actorPointer);

    EXPECT_EQ('D', my_hero.fetchedletter);
  }

  TEST(unit_test, itemTouchStartLetterU_if){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_U;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter='D';
    my_level.hero = &my_hero;

    actor.level = &my_level;
    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ('U', my_hero.fetchedletter);
  }

  TEST(unit_test, itemTouchStartLetterU_else){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_U;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter='K';
    my_level.hero = &my_hero;

    actor.level = &my_level;
    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(0, my_hero.fetchedletter);
  }

  TEST(unit_test, itemTouchStartLetterK_if){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_K;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter='U';
    my_level.hero = &my_hero;

    actor.level = &my_level;
    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ('K', my_hero.fetchedletter);
  }

  TEST(unit_test, itemTouchStartLetterK_else){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_K;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter='D';
    my_level.hero = &my_hero;

    actor.level = &my_level;
    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(0, my_hero.fetchedletter);
  }

  TEST(unit_test, itemTouchStartLetterE_if){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_E;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter='K';
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(10000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartLetterE_else){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_E;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter='A';
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(500, my_hero.score);
  }

  TEST(unit_test, itemTouchStartFullLife){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_FULL_LIFE;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(1000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartActorGun){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_GUN;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(1000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartAccessCard){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_ACCESS_CARD;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(1000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartGlove){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_GLOVE;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(1000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartBOOTS){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_BOOTS;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(1000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartCLAMPS){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_CLAMPS;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(0, actor.is_alive);
  }

  TEST(unit_test, itemTouchStartFOOTBALL){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_FOOTBALL;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(100, my_hero.score);
  }

  TEST(unit_test, itemTouchStartDisk){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_DISK;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(5000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartJoystick){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_JOYSTICK;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(2000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartFLAG0){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_FLAG;

    fn_actor_item_data_t my_data = {};
    my_data.current_frame = 0;
    actor.data = &my_data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(100, my_hero.score);
  }

  TEST(unit_test, itemTouchStartFLAG1){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_FLAG;

    fn_actor_item_data_t my_data = {};
    my_data.current_frame = 1;
    actor.data = &my_data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(2000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartFLAG2){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_FLAG;

    fn_actor_item_data_t my_data = {};
    my_data.current_frame = 2;
    actor.data = &my_data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.score = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(5000, my_hero.score);
  }

  TEST(unit_test, itemTouchStartSODA){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_SODA;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.health = 100;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(101, my_hero.health);
  }

  TEST(unit_test, itemTouchStartCHICKEN_SINGLE){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_CHICKEN_SINGLE;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.health = 100;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(101, my_hero.health);
  }

  TEST(unit_test, itemTouchStartCHICKEN_DOUBLE){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_CHICKEN_DOUBLE;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.health = 100;
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(102, my_hero.health);
  }


  // TEST fn_actor_function_singleanimation_create

    TEST(unit_test, singleanimationFIRE){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct = {0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_FIRE;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data = (fn_actor_singleanimation_data_t *)actor.data;
    int d = my_data->tile;
    EXPECT_EQ(ANIM_BOMBFIRE, d);
  }

  TEST(unit_test, singleanimationDUSTCLOUD){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_DUSTCLOUD;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t *  my_data=(fn_actor_singleanimation_data_t *)actor.data;
    int d = my_data->tile;
    EXPECT_EQ(OBJ_DUST, d);
  }

  TEST(unit_test, singleanimationSTEAM){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_STEAM;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;
    int d = my_data->tile;
    EXPECT_EQ(OBJ_STEAM, d);
  }

  TEST(unit_test, singleanimationROBOT_DISAPPEARING){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_ROBOT_DISAPPEARING;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;
    int d = my_data->tile;
    EXPECT_EQ(ANIM_ROBOT+3, d);
  }

  TEST(unit_test, singleanimationDEFAULT){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = (fn_actor_type_e)0;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;
    int d = my_data->tile;
    EXPECT_EQ(0, d);
  }
  // TEST FN_LIST_APPEND

  TEST(unit_test, list_appendEmptyList)	{

   fn_list_t newItem = {NULL,NULL};
   int data = 1;
   void * dataP = &data;
   fn_list_t newList = * fn_list_append(&newItem, dataP);
   int * d = (int *)(newList.next)->data;
   EXPECT_EQ(1, *d);

  }

  TEST(unit_test, list_appendOneElementPresent)	{

   fn_list_t item1 ={NULL,NULL};
   fn_list_t item2= {NULL,NULL};
   item1.next =&item2;
   int data = 1;
   void* dataP = &data;
   fn_list_t * newList= fn_list_append(&item1, dataP);
   fn_list_t * t = (item1.next)->next;
   int * d = (int *)t->data;
   EXPECT_EQ(1, *d);

  }

  // TEST ITEM_CREATE

  TEST(unit_test, itemCreate){

    fn_level_t my_level = {};
    fn_tilecache_t my_tilecache = {};

    fn_item_t itemStruct = *fn_item_create(FN_ITEM_TYPE_BOX_GREY_EMPTY, &my_level, &my_tilecache, 1000, 1, 1);
    fn_item_t * item = &itemStruct;

    EXPECT_EQ(item->type, FN_ITEM_TYPE_BOX_GREY_EMPTY);
    EXPECT_EQ(item->tilecache, &my_tilecache);
    EXPECT_EQ(item->pixelsize, 1000);
    EXPECT_EQ(item->x, 1);
    EXPECT_EQ(item->y, 1);
    EXPECT_EQ(item->level, &my_level);
    EXPECT_EQ(item->todelete, 0);

  }

  // TEST ITEM_ACT

  TEST(unit_test, item_actUpdated){
    fn_item_t item= {};
    fn_level_t myLevel={};
    item.level=&myLevel;
    item.x=-1;
    item.y=0;
    fn_item_act(&item);
    EXPECT_EQ( 1, item.y);
  }

  TEST(unit_test, item_actNotTodelete){
    fn_item_t item= {};
    fn_level_t myLevel={};
    item.level=&myLevel;
    item.todelete=0;
    int result= fn_item_act(&item);
    EXPECT_EQ(1, result);
  }

  TEST(unit_test, item_actTodelete){
    fn_item_t item= {};
    fn_level_t myLevel={};
    item.level=&myLevel;
    item.todelete=1;
    int result= fn_item_act(&item);
    EXPECT_EQ(0, result);
  }

  // TEST ACME_ACT

  TEST(unit_test, acme_act0bet0){
    fn_actor_t actorStruct={};
    fn_actor_t * actor=&actorStruct;
    actor->x=1;
    actor->y=-1;
    actor->w=1000000;

    fn_actor_acme_data_t dataStruct={0,0,0};
    fn_actor_acme_data_t * data = &dataStruct;
    actor->data=data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {0,0,0,0,0,0,0,0,0,0,0,1000,5,0,0,0,0,0,0};
    my_level.hero = &my_hero;
    actor->level = &my_level;

    fn_actor_function_acme_act(actor);


    EXPECT_EQ(1, data->counter);
  }


  TEST(unit_test, acme_act0bet1){
    fn_actor_t actorStruct={};
    fn_actor_t * actor=&actorStruct;
    actor->x=100000;
    actor->y=-1;
    actor->w=1000000;

    fn_actor_acme_data_t dataStruct={0,0,0};
    fn_actor_acme_data_t * data = &dataStruct;
    actor->data=data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {0,0,0,0,0,0,0,0,0,0,0,10000000,5,0,0,0,0,0,0};
    my_level.hero = &my_hero;
    actor->level = &my_level;

    fn_actor_function_acme_act(actor);


    EXPECT_EQ(0, data->counter);
  }

  TEST(unit_test, acme_act9){
    fn_actor_t actorStruct={};
    fn_actor_t * actor=&actorStruct;
    actor->y=1;

    fn_actor_acme_data_t dataStruct={0,9,0};
    fn_actor_acme_data_t * data = &dataStruct;
    actor->data=data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    my_level.hero = &my_hero;
    actor->level = &my_level;

    fn_actor_function_acme_act(actor);


    EXPECT_EQ(10, data->counter);
    EXPECT_EQ(2, actor->y);

  }

  TEST(unit_test, acme_act10){
    fn_actor_t actorStruct={};
    fn_actor_t * actor=&actorStruct;
    actor->y=1;

    fn_actor_acme_data_t dataStruct={0,10,0};
    fn_actor_acme_data_t * data = &dataStruct;
    actor->data=data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    my_level.hero = &my_hero;
    actor->level = &my_level;

    fn_actor_function_acme_act(actor);


    EXPECT_EQ(11, data->counter);
    EXPECT_EQ(0, actor->y);

  }

  TEST(unit_test, acme_actDeafaultElse){
    fn_actor_t actorStruct={};
    fn_actor_t * actor=&actorStruct;
    actor->y=1;

    fn_actor_acme_data_t dataStruct={0,34,0};
    fn_actor_acme_data_t * data = &dataStruct;
    actor->data=data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    my_level.hero = &my_hero;
    actor->level = &my_level;
    actor->is_alive = 1;

    fn_actor_function_acme_act(actor);


    EXPECT_EQ(1, actor->is_alive);

  }

  TEST(unit_test, acme_actDeafaultIf){
    fn_actor_t actorStruct={};
    fn_actor_t * actor=&actorStruct;
    actor->x=-1234;

    fn_actor_acme_data_t dataStruct={0,34,0};
    fn_actor_acme_data_t * data = &dataStruct;
    actor->data=data;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    my_level.hero = &my_hero;
    actor->level = &my_level;
    actor->is_alive = 1;

    fn_actor_function_acme_act(actor);


    EXPECT_EQ(0, actor->is_alive);

  }

  //TEST MAIN_MENU

  TEST(unit_test, mainmenuDefault){

    int result = fn_mainmenu(NULL, 100, NULL,-1, SDLK_s);
    EXPECT_EQ(-1, result);
  }

  TEST(unit_test, mainmenuKeydown_s){

    int result = fn_mainmenu(NULL, 100, NULL,SDL_KEYDOWN, SDLK_s);
    EXPECT_EQ(FN_MENUCHOICE_START, result);
  }

  TEST(unit_test, mainmenuKeydown_r){

    int result = fn_mainmenu(NULL, 100, NULL,SDL_KEYDOWN, SDLK_r);
    EXPECT_EQ(FN_MENUCHOICE_RESTORE, result);
  }

  TEST(unit_test, mainmenuKeydown_i){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_i);
    EXPECT_EQ(FN_MENUCHOICE_INSTRUCTIONS, result);
  }

  TEST(unit_test, mainmenuKeydown_o){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_o);
    EXPECT_EQ(FN_MENUCHOICE_ORDERINGINFO, result);
  }

  TEST(unit_test, mainmenuKeydown_g){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_g);
    EXPECT_EQ(FN_MENUCHOICE_SETUP, result);
  }

  TEST(unit_test, mainmenuKeydown_f){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_f);
    EXPECT_EQ(FN_MENUCHOICE_FULLSCREENTOGGLE, result);
  }

  TEST(unit_test, mainmenuKeydown_e){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_e);
    EXPECT_EQ(FN_MENUCHOICE_EPISODECHANGE, result);
  }

  TEST(unit_test, mainmenuKeydown_h){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_h);
    EXPECT_EQ(FN_MENUCHOICE_HIGHSCORES, result);
  }

  TEST(unit_test, mainmenuKeydown_p){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_p);
    EXPECT_EQ(FN_MENUCHOICE_PREVIEWS, result);
  }

  TEST(unit_test, mainmenuKeydown_v){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_v);
    EXPECT_EQ(FN_MENUCHOICE_VIEWUSERDEMO, result);
  }

  TEST(unit_test, mainmenuKeydown_t){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_t);
    EXPECT_EQ(FN_MENUCHOICE_TITLESCREEN, result);
  }

  TEST(unit_test, mainmenuKeydown_c){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_c);
    EXPECT_EQ(FN_MENUCHOICE_CREDITS, result);
  }

  TEST(unit_test, mainmenuKeydown_q){

    int result = fn_mainmenu(NULL, 100, NULL, SDL_KEYDOWN, SDLK_q);
    EXPECT_EQ(FN_MENUCHOICE_QUIT, result);
  }


  //TEST fn_hero_act

  TEST(unit_test, hero_actImmunitycountdown){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->immunitycountdown=3;

    void * data=NULL;
    fn_hero_act(hero, data);

    EXPECT_EQ(2, hero->immunitycountdown);
  }

  TEST(unit_test, hero_actHurtingactors){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->immunitycountdown=0;
    hero->immunityduration=5;
    fn_list_t * next=NULL;
    void * dataP=NULL;
    fn_list_t MyhurtingactorsStruct={next, dataP};
    fn_list_t * Myhurtingactors=&MyhurtingactorsStruct;
    hero->hurtingactors=Myhurtingactors;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    fn_hero_act(hero, data);

    EXPECT_EQ(5, hero->immunitycountdown);
  }


  TEST(unit_test, hero_actDataNULL){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->health=3;
    void * data=NULL;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(3, rst);
  }


  TEST(unit_test, hero_actMotionLeft){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->direction=fn_horizontal_direction_left;
    hero->x=7;
    hero->y=7;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(6, hero->x);
  }

  TEST(unit_test, hero_actMotionRight){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->direction=fn_horizontal_direction_right;
    hero->x=7;
    hero->y=7;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(8, hero->x);
  }

 TEST(unit_test, hero_actMotionDefault){
   fn_hero_t heroStruct={};
   fn_hero_t * hero=&heroStruct;

   hero->motion = FN_HERO_MOTION_WALKING;
   hero->direction=  fn_horizontal_direction_size;
   hero->x=7;
   hero->y=7;

   fn_level_t dataStruct={};
   void * data=&dataStruct;
   int rst =fn_hero_act(hero, data);

   EXPECT_EQ(7, hero->x);
  }

  TEST(unit_test, hero_actFlying){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;
    hero->flying = FN_HERO_FLYING_FALSE;
    hero->verticalspeed = 1;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    fn_hero_act(hero, data);

    EXPECT_EQ(2, hero->verticalspeed);
  }

  TEST(unit_test, hero_actNotFlying1){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->verticalspeed = 7;
    hero->counter = 4;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    fn_hero_act(hero, data);

    EXPECT_EQ(1, hero->verticalspeed);
  }

  TEST(unit_test, hero_actNotFlying0){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->verticalspeed = 7;
    hero->counter = 2;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    fn_hero_act(hero, data);

    EXPECT_EQ(0, hero->verticalspeed);
  }

  TEST(unit_test, hero_actNotFlying2){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->verticalspeed = 7;
    hero->counter = 9;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    fn_hero_act(hero, data);

    EXPECT_EQ(2, hero->verticalspeed);
  }

  TEST(unit_test, hero_actNotCollide1){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->direction=  fn_horizontal_direction_size;
    hero->x=7;
    hero->y=7;
    hero->counter = 9;
    hero->verticalspeed=1;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(5, hero->y);
  }

  TEST(unit_test, hero_actNotCollide2){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->direction=  fn_horizontal_direction_size;
    hero->x=7;
    hero->y=7;
    hero->counter = 9;
    hero->verticalspeed=2;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(5, hero->y);
  }

  TEST(unit_test, hero_actNegCount1){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->direction=  fn_horizontal_direction_size;
    hero->x=7;
    hero->y=7;
    hero->counter = -3;
    hero->verticalspeed=2;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(3, hero->verticalspeed);
  }

 TEST(unit_test, hero_actNegCount2){
   fn_hero_t heroStruct={};
   fn_hero_t * hero=&heroStruct;

   hero->motion = FN_HERO_MOTION_WALKING;
   hero->flying = FN_HERO_FLYING_TRUE;
   hero->direction=  fn_horizontal_direction_size;
   hero->x=7;
   hero->y=7;
   hero->counter = -3;
   hero->verticalspeed=4;

   fn_level_t dataStruct={};
   void * data=&dataStruct;
   int rst =fn_hero_act(hero, data);

   EXPECT_EQ(9, hero->y);
  }

  TEST(unit_test, hero_actColl){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->direction=  fn_horizontal_direction_size;
    hero->x=-7;
    hero->y=-7;
    hero->counter = 3;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    fn_hero_act(hero, data);

    EXPECT_EQ(0, hero->counter);
  }

  TEST(unit_test, hero_actNotColl){
    fn_hero_t heroStruct={};
    fn_hero_t * hero=&heroStruct;

    hero->motion = FN_HERO_MOTION_WALKING;
    hero->flying = FN_HERO_FLYING_TRUE;
    hero->direction=  fn_horizontal_direction_size;
    hero->x=7;
    hero->y=7;
    hero->counter = 0;

    fn_level_t dataStruct={};
    void * data=&dataStruct;
    int rst =fn_hero_act(hero, data);

    EXPECT_EQ(0, hero->counter);
  }

}

