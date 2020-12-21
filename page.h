// Tactics Game UI by Jeffrey Jerstrom
// Page class 
//
// The page is a list of elements that displays them in a FILO (stack) order. The
// element class is a ABC to allow for different types of elements with one
// interface for the page to use. The list cannot own the element objects unless
// RTTI or a type flag is used which unfortuatly prevents the client from deriving
// their own elements (one of the goals of my design). 
//
// This means that the client will have to manage the memory for the elements
// they create. I have tried to avoid this situation, but have come up empty
// handed. The client can ether:
//	 1. Use dynamic memory and be trusted to delete it
//   2. Use smart pointers
//   3. Declare the elements as global variables
//
// I don't like any of those options, but until there is a better solution, we
// are stuck with them. One possiblity is that the ui class manages the memory,
// but I haven't yet worked out the details.

#include <cstring>
#include <string>
#include "SFML/Graphics.hpp"
#include "element.h"
using namespace std;

class page : public element
{
	public:
		page();
		~page();
	  bool addElement(element & toadd);
		int removeElement(const string tocomp);
    void draw(sf::RenderWindow &window, sf::Texture &ui_texture);

	private:
		element * head;
};
