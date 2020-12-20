// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

#include "page.h"

page::page() : element() 
  
{
  head = NULL;
}

page::~page()
{

}

int page::addElement(element & toadd)
{
  // Empty List
  if (!head) {
    head = &toadd;
    head->next = NULL; 
  }

  // Non-Empty List
  element * current = head;
  head = &toadd;
  head->next = current;

  return 0;  // Sucess
}

