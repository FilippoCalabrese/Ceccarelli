#include <limits.h>
#include "funzioniNonModificate.h"
#include "gtest/gtest.h"
namespace {

//TEST fn_actor_touches_hero

  TEST(TestNonModificati, testTouchesLeft){
    fn_actor_t actor = {
      100, 100, 1, 1, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(TestNonModificati, testTouchesRight){
    fn_actor_t actor = {
      1, 1, 1, 1, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(TestNonModificati, testTouchesAbove){
    fn_actor_t actor = {
      1, 100, 1000, 1, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(TestNonModificati, testTouchesBelow){
    fn_actor_t actor = {
      1, 1, 100, 20, 1, 1, 1
    };
    EXPECT_EQ(0, fn_actor_touches_hero(&actor));
  }

  TEST(TestNonModificati, testTouchesOther){
    fn_actor_t actor = {
      1, 1, 1000, 1000, 1, 1, 1
    };
    EXPECT_EQ(1, fn_actor_touches_hero(&actor));
  }

// TEST fn_actor_function_redball_lying_act

  TEST(TestNonModificati, testRedballLyingWithTrueValue){

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


  TEST(TestNonModificati, testRedballLyingWithFalseValue){

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

  TEST(TestNonModificati, itemTouchStartLetterD){
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

  TEST(TestNonModificati, itemTouchStartLetterU){
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

  TEST(TestNonModificati, itemTouchStartLetterE){
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

  TEST(TestNonModificati, itemTouchStartCLAMPS){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_CLAMPS;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_level.hero = &my_hero;

    actor.level = &my_level;

    fn_actor_function_item_touch_start(&actor);

    EXPECT_EQ(0, actor.is_alive);
  }

  TEST(TestNonModificati, itemTouchStartFLAG){
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

  TEST(TestNonModificati, itemTouchStartSODA){
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

  TEST(TestNonModificati, itemTouchStartCHICKEN_DOUBLE){
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
  
    TEST(TestNonModificati, singleanimationFIRE){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_FIRE;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;

    EXPECT_EQ(ANIM_BOMBFIRE, my_data->tile);
}

    TEST(TestNonModificati, singleanimationDUSTCLOUD){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_DUSTCLOUD;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t *  my_data=(fn_actor_singleanimation_data_t *)actor.data;

    EXPECT_EQ(OBJ_DUST, my_data->tile);
}

    TEST(TestNonModificati, singleanimationSTEAM){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_STEAM;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;

    EXPECT_EQ(OBJ_STEAM, my_data->tile);
}

    TEST(TestNonModificati, singleanimationROBOT_DISAPPEARING){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = FN_ACTOR_ROBOT_DISAPPEARING;
    fn_actor_t * actorPointer = &actor; 
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;

    EXPECT_EQ(ANIM_ROBOT+3, my_data->tile);
}

    TEST(TestNonModificati, singleanimationDEFAULT){
    fn_actor_t actor = {};
    fn_actor_singleanimation_data_t dataStruct ={0,0,0};
    actor.data= &dataStruct;
    actor.type = (fn_actor_type_e)0;
    fn_actor_t * actorPointer = &actor;
    fn_actor_function_singleanimation_create(actorPointer);
    fn_actor_singleanimation_data_t * my_data=(fn_actor_singleanimation_data_t *)actor.data;

    EXPECT_EQ(0, my_data->tile);
}

  // TEST FN_LIST_APPEND

  TEST(TestNonModificati, list_appendEmptyList)	{

   fn_list_t newItem ={NULL,NULL};
   int data=1;
   void* dataP = &data;
   fn_list_t * newList= fn_list_append(&newItem, dataP);
   EXPECT_EQ(dataP, (newItem.next)->data);
    
  }
  
  TEST(TestNonModificati, list_appendOneElementPresent)	{
    
   fn_list_t item1 ={NULL,NULL};
   fn_list_t item2= {NULL,NULL};
   item1.next =&item2;
   int data=1;
   void* dataP = &data;
   fn_list_t * newList= fn_list_append(&item1, dataP);
   fn_list_t * t = (item1.next)->next;
   EXPECT_EQ(dataP, t->data);
    
  }
  
  // TEST ITEM_CREATE

  TEST(TestNonModificati, itemCreate){	
    
    fn_level_t my_level = {};
    fn_item_t my_item = {0,1000, 1, 1, &my_level, 0};

    fn_item_t * item = fn_item_create(FN_ITEM_TYPE_BOX_GREY_EMPTY, &my_level, 1000, 1, 1);
    EXPECT_EQ(item->pixelsize, my_item.pixelsize);
    EXPECT_EQ(item->level, my_item.level);
    EXPECT_EQ(item->todelete, my_item.todelete);
    EXPECT_EQ(item->x, my_item.x);
    EXPECT_EQ(item->y, my_item.y);
  }
  
  // TEST ITEM_ACT

  TEST(TestNonModificati, item_actUpdated){
  fn_item_t item= {};
  fn_level_t myLevel={};
  item.level=&myLevel;
  item.x=-1;
  item.y=0;
  fn_item_act(&item);
  EXPECT_EQ( 1, item.y);
  }	
  
  TEST(TestNonModificati, item_actNotTodelete){
  fn_item_t item= {};
  fn_level_t myLevel={};
  item.level=&myLevel;
  item.todelete=0;
  int result= fn_item_act(&item);
  EXPECT_EQ(1, result);
  }	
  
  TEST(TestNonModificati, item_actTodelete){
  fn_item_t item= {};
  fn_level_t myLevel={};
  item.level=&myLevel;
  item.todelete=1;
  int result= fn_item_act(&item);
  EXPECT_EQ(0, result);
  }	



   
}























