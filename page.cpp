// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

#include "page.h"

page::page() : element() 
{
  head = NULL;
}

page::~page()
{
	head = NULL;
}

bool page::addElement(element & toadd)
{
	if (toadd.next) 
		return false;  // Fail - No double assignment!
	                 // Do I still need this?

  // Empty List
  if (!head) {
    head = &toadd;
    head->next = NULL; 
		return true;
  }

  // Non-Empty List
  element * current = head;
  head = &toadd;
  head->next = current;

  return true;  // Sucess
}

int page::removeElement(const string tocomp)
{
	// Empty List
	if (!head) 
		return 1;  // Fail - Empty List

	// Remove at the front
	if (head->compare(tocomp)) {
		head = head->next;
		return 0;  // Success
	}

	element * current = head->next; 
	element * previous = head;

	// Remove from the middle or end
  while (current) {
	  if (current->compare(tocomp)) {
			previous->next = current->next;
			return 0;  // Success
		}
		previous = current;
	  current = current->next;
	}	

	return 2;  // Fail - Not found
}

void page::draw(sf::RenderWindow &window, sf::Texture &ui_texture)
{
  if (!head) return;  //Fail - Empty List

	element * current = head;

	while (current) {
		current->display(window, ui_texture);
		current = current->next;
	}

	return; // Success;
}


	
