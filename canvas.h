// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

#include <iostream>
#include <cstring>
#include <string>
#include "SFML/Graphics.hpp"
#include "element.h"

// It is best if canvas are created in multiples of tile sizes to save on calc
// time. Remainders are costly!
//
// Use canvasdefs.h to set sprite sheet locations

class canvas : public element
{
  public:
    canvas(std::string initTitle, sf::IntRect &location);

    int move(int byX, int byY);
    int put(int toX, int toY);
    int changeSize(int toX, int toY);

    int getLocation(sf::IntRect &toAdd);
    int draw(sf::RenderWindow &window, sf::Texture &ui_texture);
    void display();  // switch draw! 

  private:
    // This can save time by not calc on the fly, but is not enforced!
    // There must be an update for every change.
		// New idea: implemtent this in the func it should accompany!
    void update();
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

/*
// Put this somewhere else?
struct elementNode 
{
	elelment * data;  // Needs to be a pointer to hold diff types
	node * next;
};


class page : public element 
{
  public:
    page(std::string initTitle, sf::IntRect & location);
    ~page();
    int addElement(element & toadd);
    int removeElement(const char * name);
    int displayPage();  // or maybe call it draw?	

  private:
    bool compare(const element & comp);

    element * head;
};
*/
