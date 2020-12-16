#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "page.h"
#include "pagedefs.h"

using namespace sf;
using namespace std;

int main()
{
  RenderWindow window(VideoMode(1280, 720), "Tactics Game UI");

	// Window Background
	RectangleShape window_background(Vector2f(1280, 720));
	//window_background.setFillColor(

  // Test Page!
  Texture ui_texture;

  if (!ui_texture.loadFromFile("Textures/ui_texture2.png"))
    cout << endl << "Can't find Textures/ui_texture2.png\n";

  IntRect location(200,200,350,350);

  page test_page("Test Page", location);

  // Main Loop
  while (window.isOpen()) {

    Event event;

    // Check for Events
    while (window.pollEvent(event)) {

      // Close Event
      if (event.type == Event::Closed)
	window.close();
    }

    // Fresh Canvas
    window.clear();

    // Draw Everything
		// Draw Background
		window.draw(window_background);

    test_page.draw(window, ui_texture);

    // Display All
    window.display();
  }

  return 0;
}


