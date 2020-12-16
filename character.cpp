// Character Class

#include "character.h"

character::character(char_stats const & statSeed)
{
  cstats.name = statSeed.name;
  cstats.level = statSeed.level;
  cstats.exp = statSeed.exp;
}

// I'm going to be made if I can just to_copy = cstats
void character::copy_cstat(char_stats & to_copy) const
{
  to_copy.name = cstats.name;
  to_copy.level = cstats.level;
  to_copy.exp = cstats.exp;

  return;
}

void character::copy_rstat(root_stats & to_copy) const
{
  to_copy.endurance = rstats.endurance;
  to_copy.strength = rstats.strength;
  to_copy.spirit = rstats.spirit;
  to_copy.speed = rstats.speed;
  to_copy.element = rstats.element;

  return;
}

void character::copy_bstat(battle_stats & to_copy) const
{
  to_copy.hp = bstats.hp;
  to_copy.mp = bstats.mp;
  to_copy.attack = bstats.attack;
  to_copy.defense = bstats.defense;
  to_copy.ready = bstats.ready;
  to_copy.mattack = bstats.mattack;
  to_copy.mdefense = bstats.mdefense;
  to_copy.status = bstats.status;

  return;
}

int character::displayBasic()
{
	

	return 0;
}

//           ___________________________________
//          /      /      /      /      /      /|
//         /      /      /      /      /      / / 
//        /______/______/______/______/______/ /
//       /      /      /      /      /      / /
//      /      /      /      /      /      / / 
//     /______/______/______/______/______/ /
//    /      /      /      /      /      / /
//   /      /      /      /      /      / / 
//  /______/______/______/______/______/ /
//  |__________________________________|/








