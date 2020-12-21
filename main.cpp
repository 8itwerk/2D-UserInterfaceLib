#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "page.h"
#include "canvas.h"

using namespace sf;
using namespace std;

int main()
{
	/*
  IntRect test_location(200,200,350,350);
  page test_page("title", test_location);

  element * test_element;

  test_element = new page(test_page);
	*/

  
  page test_page;


  RenderWindow window(VideoMode(1280, 720), "Tactics Game UI");

	// Window Background
	RectangleShape window_background(Vector2f(1280, 720));
	//window_background.setFillColor(

  // Test Page!
  Texture ui_texture;

  if (!ui_texture.loadFromFile("Textures/ui_texture2.png"))
    cout << endl << "Can't find Textures/ui_texture2.png\n";

  IntRect location(200,200,350,350);

  canvas test_canvas("Test Page", location);

	test_page.addElement(test_canvas);

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

    //test_canvas.display(window, ui_texture);
		test_page.draw(window, ui_texture);

    // Display All
    window.display();
  }

  return 0;
}


