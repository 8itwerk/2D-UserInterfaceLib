// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

#include <iostream>
#include <cstring>
#include <string>
#include "SFML/Graphics.hpp"

// It is best if canvass are created in multiples of tile sizes to save on calc time
// Remainders are costly!
//
// Use canvasdefs.h to set sprite sheet locations

class canvas
{
  public:
    canvas(std::string initTitle, sf::IntRect &location);

    int move(int byX, int byY);
    int put(int toX, int toY);
    int changeSize(int toX, int toY);

    // This can save time by not calc on the fly, but is not enforced!
    // There must be an update for every change.
    void update();

    int getLocation(sf::IntRect &toAdd);

    int draw(sf::RenderWindow &window, sf::Texture &ui_texture);

  private:
    int drawBG(sf::RenderWindow &window, sf::Texture &ui_texture);
    int drawBorder(sf::RenderWindow &window, sf::Texture &ui_texture);
    int drawCorners(sf::RenderWindow &window, sf::Texture &ui_texture);

    std::string title;

    sf::IntRect location;

    sf::Texture ui_texture;
    sf::Sprite cv_sprite;  

    int columns;
    int column_rem;
    int rows;
    int row_rem;
};





