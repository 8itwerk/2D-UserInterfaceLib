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
    //element(const element & tocopy);
    virtual void display() = 0;
    element * next;  // Still wrestling with the location of theis next ptr

  protected:
    // Make a method to access this privately 
    //element * next;  // Still wrestling with the location of theis next ptr

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
};

#endif
