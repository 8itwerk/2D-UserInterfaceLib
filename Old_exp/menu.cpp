#include "menu.h"

/*
class menu
{
	public:
		menu();
		void setBG();
		void setFont();
		void setCursor();


	private:
		int xpos, ypos;  // Top left corner of the menu
		int index;       // Menu item selection

		
};
*/

menu::menu()
{
	xpos = 200;
	ypos = 200;

	// Load Background
	if (!menu_texture.loadFromFile("Textures/menu_bg.png"))
		cout << endl << "Can't find menu_bg.png texture file" << endl;
	
	// Load Font
  if (!menu_font.loadFromFile("monogram.ttf"))
		cout << endl << "Can't find monogram.ttf font file" << endl;


	menu_bgsprite.setTexture(menu_texture);
	menu_bgsprite.setTextureRect(IntRect(0,0,200,400));
	menu_bgsprite.setPosition(xpos, ypos);  // Switch?


	menu_text.setFont(menu_font);
	menu_text.setPosition(xpos + 30, ypos + 10);
	menu_text.setCharacterSize(24);
	menu_text.setFillColor(Color::Black);
	menu_text.setString("Item 1\nItem 2\nItem 3\nItem 4");




}

void menu::setBG()
{

}

void menu::setFont()
{

}

void menu::setCursor()
{

}

uint menu::getCursorY()
{
  return menu_font.getLineSpacing(24);
}

void menu::draw(RenderWindow & window)
{
  window.draw(menu_bgsprite);
	window.draw(menu_text);
}
