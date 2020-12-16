// Tactics Game UI by Jeffrey Jerstrom
// Element ABC for pages 

#include <cstring>
#include <string>
#include "SFML/Graphics.hpp"

enum type {ITEM,PORTRAIT,TEXT,ICON,CURSOR}

class element
{
  public:
    element();
    virtual void display() = 0;

  private:
    string name;
    int type;
    sf::IntRect location;
};

class text: public element
{
  public:
    text();


  private:
}

