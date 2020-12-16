// Tactics Game by Jeffrey Jernstrom
// Roster 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "defs.h"

using namespace sf;
using namespace std;

class gui
{
	public:
		gui();
		void display_circle(RenderWindow & window);
		void display_texttest(RenderWindow & window, Font & font);
		void display_icontest(RenderWindow & window, Texture & texture);
	
	private:


};


/*
class display
{
  public:
    display();
    ~display();
    void display_stats();
    void display_char_stats();
    void display_equip();

  private:
    char_stats current_cstats;
    root_stats current_rstats;
    battle_stats current_bstats;
};
*/
