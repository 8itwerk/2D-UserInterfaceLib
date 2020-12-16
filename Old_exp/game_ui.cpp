//
//

#include "game_ui.h"

gui::gui()
{

}



void gui::display_circle(RenderWindow &window)
{

	// should go somewhere else
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	window.draw(shape);
	
	return;
}



void gui::display_texttest(RenderWindow & window, Font & font)
{

	Text text;
	text.setFont(font);
	text.setPosition(50.f, 0.f);
	text.setString("Hello World!\nWill this show the next line?");
	text.setCharacterSize(24);
	text.setFillColor(Color::White);
	//text.setOutlineColor(Color::Red);  // Totally Works!!!
	//text.setOutlineThickness(1.f);

	window.draw(text);

	return;
}

void gui::display_icontest(RenderWindow & window, Texture & texture)
{

	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(398,277,421,287));


	return;
}
