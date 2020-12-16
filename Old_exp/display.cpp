#include "ui.h"
#include <iostream>
using namespace std;

display::display()
{

}



void display::display_stats()
{
  cout << "Base Stats" << endl
       << "\tEndurance:\t" << current_rstats.endurance << endl
       << "\tStrength:\t" << current_rstats.strength << endl
       << "\tSpirit:\t" << current_rstats.spirit << endl
       << "\tSpeed:\t" << current_rstats.speed << endl
       << "\tMove:\t" << "Not Implemented..." << endl
       << "\tJump:\t" << "Not Implimented..." << endl;

  return;
}

void display::display_char_stats()
{
  cout << "Character Stats" << endl
       << "\tLevel:\t" << current_cstats.level << endl
       << "\tExp:\t" << current_cstats.exp << endl;

  return;
}

void display::display_equip()
{
  cout << "Equipment" << endl
       << "\tR. Hand:\t" << endl
       << "\tL. Hand:\t" << endl
       << "\tBody:\t" << endl
       << "\tHead:\t" << endl
       << "\tAccesory:\t" << endl;

  return;
}
