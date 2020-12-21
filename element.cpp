// Tactics Game UI by Jeffrey Jerstrom
// Element ABC for pages 

#include "element.h"

element::element()
{
	name = "none";
  next = NULL;
}

bool element::compare(const string tocomp)
{
	if (name == tocomp)
		return true;
	else
		return false;
}

