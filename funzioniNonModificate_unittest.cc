
#include <limits.h>
#include "sample1.h"
#include "funzioniNonModificate.h"
#include "gtest/gtest.h"
namespace {

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


  TEST(TestNonModificati, testRedballLyingWithTrueValue){

    //inizializzazione delle strutture necessarie
    fn_actor_redball_lying_data_t dataStruct = {
      1, 1
    };
    fn_actor_redball_lying_data_t * data = &dataStruct;
    fn_actor_t actorStruct = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, data
    };
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
    fn_actor_t actorStruct = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, data
    };
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

  TEST(TestNonModificati, itemTouchStartLetterD){
    fn_actor_t actor = {};
    actor.type = FN_ACTOR_LETTER_D;

    fn_level_t my_level = {};
    fn_hero_t my_hero = {};
    my_hero.fetchedletter = 0;
    my_level.hero = &my_hero;

    actor.level = &my_level;
    fn_actor_function_item_touch_start(&actor);

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
}
