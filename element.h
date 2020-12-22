// Tactics Game UI by Jeffrey Jerstrom
// Element ABC for pages 
// Tactics Game UI by Jeffrey Jerstrom
// Element ABC for pages 

#include <cstring>
#include <string>
#include "SFML/Graphics.hpp"
#ifndef ELEMENT_H
#define ELEMENT_H

using namespace std;

enum type {ITEM,PORTRAIT,TEXT,ICON,CURSOR};

class element
{
  public:
    element();
    virtual void draw(sf::RenderWindow &window, sf::Texture &ui_texture) = 0;
    bool compare(const string tocomp);

    element * next;  // Still wrestling with the location of theis next ptr

  protected:
    // Make a method to access this privately 

  private:
    string name;
    int type;
    sf::IntRect location;
};

struct node
{
  element * data;
  node * next;
};

class text: public element
{
  public:
    text();
    void draw(sf::RenderWindow &window, sf::Texture &ui_texture);

  private:
};

#endif
