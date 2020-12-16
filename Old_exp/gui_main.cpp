#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "menu.h"
#include "page.h"
#include "pagedefs.h"

using namespace sf;

int main()
{
  RenderWindow window(VideoMode(1280, 720), "Tactics Game UI");
	//gui game_gui;

	// Load and test sound effect
	SoundBuffer buffer;
	if (!buffer.loadFromFile("button_click.wav"))
		cout << endl << "Can't find button_click.wav sound file" << endl;

	Sound sound;
	sound.setBuffer(buffer);

	// Load and print test font
	Font font;
  if (!font.loadFromFile("monogram.ttf"))
		cout << endl << "Can't find monogram.ttf font file" << endl;

	Text text;
	text.setFont(font);
	text.setPosition(50.f, 0.f);
	text.setString("Hello World!\nWill this show the next line?");
	text.setCharacterSize(24);
	text.setFillColor(Color::White);

	// Load and print test sprtie
	// Figure out color masking...
	Texture texture;
	if (!texture.loadFromFile("test_icons.png"))
		cout << endl << "Can't find test_icons.png texture file" << endl;

	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(398,277,23,10));
	sprite.setPosition(200, 224); 

	menu test_menu;

	// Test the size of the sprite
	FloatRect spritesize = sprite.getLocalBounds();

	cout << endl << "Height: " << spritesize.height << " Width: "
	     <<	spritesize.width << endl;

	// Test Joystick connection
	Joystick::update();  // Do I need to do this?
	if (Joystick::isConnected(0))
		cout << endl << "Joystick 0 is connected!" << endl;

        // Page Test !!!!!
	Texture ui_texture;
	if (!texture.loadFromFile("Textures/ui_texture.png"))
		cout << endl << "Can't find ui_texture.png texture file" << endl;

	/*
	Sprite test;
	test.setTexture(ui_texture);
        test.setTextureRect(sf::IntRect
          (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));
        test.setPosition(200, 400);
        */

        IntRect location(800,200,200,200);

	page test_page("test", location);

	// Main Loop
	while (window.isOpen()) {

		Event event;

		// Check for events
		while (window.pollEvent(event)) {

			// Check for the "close" event
			if (event.type == Event::Closed)
				window.close();

			int cursorYOffset = test_menu.getCursorY();

			//cout << endl << "Cursor offset = " << cursorYOffset << endl;

			float x = Joystick::getAxisPosition(0, Joystick::X);
			float y = Joystick::getAxisPosition(0, Joystick::Y);

			if (x > 0) {
				sound.play();
				sprite.move (20.f,0.f);
			}
			else if (x < 0) {
				sound.play();
				sprite.move (-20.f,0.f);
			}
			if (y > 0) {
				sound.play();
				sprite.move (0.f,cursorYOffset);
			}
			else if (y < 0){
				sound.play();
				sprite.move (0.f,-cursorYOffset);
		  }
		}
		
		// Blank canvas
		window.clear();

		// Draw everything here
		test_menu.draw(window);

		window.draw(text);
		window.draw(sprite);
                test_page.draw(window, ui_texture);
	//	window.draw(test);

		
    // Display everything drawn to the window buffer
		window.display();
	}

	return 0;
}

