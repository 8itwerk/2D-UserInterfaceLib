#include "SFML/Graphics.hpp"
#include <iostream>
#include "defs.h"

using namespace std;
using namespace sf;

class menu
{
	public:
		menu();
		void setBG();
		void setFont();
		void setCursor();
		uint getCursorY();
		void draw(RenderWindow & window);


	private:
		int xpos, ypos;  // Top left corner of the menu
		int index;       // Menu item selection

		Texture menu_texture;
		Sprite menu_bgsprite;
		Font menu_font;
		Text menu_text;

};

class menu_stack
{
	public:

	private:

};
