// Tactics Game UI by Jeffrey Jerstrom
// Page class 
//
// The page is a list of elements that displays them in a FIFO order. The
// element class is a ABC to allow for different types of elements with one
// interface for the page to use. The list cannot own the element objects unless
// RTTI or any type flag is used which also prevents the client from deriving
// their own elements. 
//
// This means that the client will have to manage the memory for the elements
// they create. I have tried to avoid this situation, but have come up empty
// handed. The client can ether:
//	 1. Use dynamic memory and be trusted to delete it
//   2. Use smart pointers
//   3. Declare the elements as global variables
//
// I don't like any of those options, but until there is a better solution, we
// are stuck with them. 

#include "element.h"

class page : public element
{
	public:
		page();
		~page();
	  int addElement(element & toadd);
		int removeElement(const char * name);
    int displayPage();
		

	private:
		bool compare(const element & comp);

		element * head;
};
