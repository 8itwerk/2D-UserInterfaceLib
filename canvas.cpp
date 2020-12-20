// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

#include "canvas.h"
#include "canvasdefs.h"

using namespace std;

// Remember how to do an init list?
canvas::canvas(string initTitle, sf::IntRect &initLocation) : element()
{
  title = initTitle;

  location.left = initLocation.left;
  location.top = initLocation.top;
  location.width = initLocation.width;
  location.height = initLocation.height;

  // Count the number tile of Columns
  columns = location.width / BGTILE_XSIZE;
  column_rem = location.width % BGTILE_XSIZE;

  // Count the number tile rows
  rows = location.height / BGTILE_YSIZE;
  row_rem = location.height % BGTILE_XSIZE;
}

int canvas::move(int byX, int byY)
{
  location.left += byX;
  location.top += byY;
  
	update();

  return 0;
}

int canvas::put(int toX, int toY)
{
  location.left += toX;
  location.top += toY;

	update();
  
  return 0;
}

int canvas::changeSize(int toX, int toY)
{
  location.width = toX;
  location.height = toY;

	update();

  return 0;
}

int canvas::getLocation(sf::IntRect &toAdd)
{
  toAdd.left = location.left;
  toAdd.top = location.top;
  toAdd.width = location.width;
  toAdd.height = location.height;

  return 0;
}

void canvas::update()
{
  // Count the number tile of Columns
  columns = location.width / BGTILE_XSIZE;
  column_rem = location.width % BGTILE_XSIZE;

  // Count the number tile rows
  rows = location.height / BGTILE_YSIZE;
  row_rem = location.height % BGTILE_XSIZE;

	return;
}

int canvas::draw(sf::RenderWindow &window, sf::Texture &ui_texture)
{
  drawBG(window, ui_texture); 

  drawBorder(window, ui_texture);

  drawCorners(window, ui_texture);

  return 0;
}

int canvas::drawBG(sf::RenderWindow &window, sf:: Texture &ui_texture)
{
  // Use update() here if client cannot be bothered

  // Set the texture
  cv_sprite.setTexture(ui_texture);

  cv_sprite.setTextureRect(sf::IntRect
    (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));

  // Draw Rows and Columns
  for (int j = 0; j < rows; ++j) {
    for (int i = 0; i < columns; ++i) {
      cv_sprite.setPosition(location.left + (i * BGTILE_XSIZE),
                            location.top + (j * BGTILE_YSIZE));
      window.draw(cv_sprite);
    }

    if (column_rem != 0) {
      // Custom tile size to make up remainder
      cv_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, column_rem, BGTILE_YSIZE));
      cv_sprite.setPosition(location.left + (columns * BGTILE_XSIZE), 
	      location.top + (j * BGTILE_YSIZE));
      window.draw(cv_sprite);
      // Reset Tile Size
      cv_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));
    }
  }

  if (row_rem != 0) {
    for (int i = 0; i < columns; ++i) {
      // Custom tile size to make up remainder
      cv_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, row_rem));
      cv_sprite.setPosition(location.left + (i * BGTILE_XSIZE), 
	      location.top + (rows * BGTILE_YSIZE));
      window.draw(cv_sprite);
    }

    if (column_rem != 0) {
      // Custom tile size to make up remainder
      cv_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, column_rem, row_rem));
      cv_sprite.setPosition(location.left + (columns * BGTILE_XSIZE), 
	      location.top + (rows * BGTILE_XSIZE));
      window.draw(cv_sprite);
      // Reset Tile Size
      cv_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));
    }
  }

  return 0;
}

int canvas::drawBorder(sf::RenderWindow & window, sf::Texture &ui_texture)
{
	// Top Border
  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_TOP_XLOC, BORDER_TOP_YLOC, BORDER_TOP_XSIZE, BORDER_TOP_YSIZE));

	for (int i = 0; i < columns; ++i) {
		cv_sprite.setPosition(location.left + (BORDER_TOP_XSIZE * i), location.top - BORDER_TOP_YSIZE);
		window.draw(cv_sprite);
	}

  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_TOP_XLOC, BORDER_TOP_YLOC, column_rem, BORDER_TOP_YSIZE));

	if (column_rem != 0) {
		cv_sprite.setPosition(location.left + (BORDER_TOP_XSIZE * columns),
			                    location.top - BORDER_TOP_YSIZE);
		window.draw(cv_sprite);
	}


	// Bottom Border
  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_BOTTOM_XLOC, BORDER_BOTTOM_YLOC, BORDER_BOTTOM_XSIZE, BORDER_BOTTOM_YSIZE));

	for (int i = 0; i < columns; ++i) {
		cv_sprite.setPosition(location.left + (BORDER_BOTTOM_XSIZE * i), 
				                  location.top + location.height);
		window.draw(cv_sprite);
	}

  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_BOTTOM_XLOC, BORDER_BOTTOM_YLOC, column_rem, BORDER_BOTTOM_YSIZE));

	if (column_rem != 0) {
		cv_sprite.setPosition(location.left + (BORDER_BOTTOM_XSIZE * columns),
			                    location.top + location.height);
		window.draw(cv_sprite);
	}
		
	// Left Border
  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_LEFT_XLOC, BORDER_LEFT_YLOC, BORDER_LEFT_XSIZE, BORDER_LEFT_YSIZE));

	for (int j = 0; j < rows; ++j) {
		cv_sprite.setPosition(location.left - BORDER_LEFT_XSIZE, 
				                  location.top + (BORDER_LEFT_YSIZE * j));
		window.draw(cv_sprite);
	}

  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_LEFT_XLOC, BORDER_LEFT_YLOC, BORDER_LEFT_XSIZE, row_rem));

	if (row_rem != 0) {
		cv_sprite.setPosition(location.left - BORDER_LEFT_XSIZE,
			                    location.top + (BORDER_LEFT_YSIZE * rows));
		window.draw(cv_sprite);
	}
		
	// Right Border
  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_RIGHT_XLOC, BORDER_RIGHT_YLOC, BORDER_RIGHT_XSIZE, BORDER_RIGHT_YSIZE));

	for (int j = 0; j < rows; ++j) {
		cv_sprite.setPosition(location.left + location.width, 
				                  location.top + (BORDER_RIGHT_YSIZE * j));
		window.draw(cv_sprite);
	}

  cv_sprite.setTextureRect(sf::IntRect
	  (BORDER_RIGHT_XLOC, BORDER_RIGHT_YLOC, BORDER_RIGHT_XSIZE, row_rem));

	if (row_rem != 0) {
		cv_sprite.setPosition(location.left + location.width,
			                    location.top + (BORDER_RIGHT_YSIZE * rows));
		window.draw(cv_sprite);
	}
		
  return 0;
}

int canvas::drawCorners(sf::RenderWindow & window, sf::Texture &ui_texture)
{
	// Top Left
  cv_sprite.setTextureRect(sf::IntRect
	  (CORNER_TL_XLOC, CORNER_TL_YLOC, CORNER_TL_XSIZE, CORNER_TL_YSIZE));
	cv_sprite.setPosition(location.left - CORNER_TL_XSIZE, location.top - CORNER_TL_YSIZE);
	window.draw(cv_sprite);

	// Top Right
  cv_sprite.setTextureRect(sf::IntRect
	  (CORNER_TR_XLOC, CORNER_TR_YLOC, CORNER_TR_XSIZE, CORNER_TR_YSIZE));
	cv_sprite.setPosition(location.left + location.width, location.top - CORNER_TL_YSIZE);
	window.draw(cv_sprite);

	// Bottom Left
  cv_sprite.setTextureRect(sf::IntRect
	  (CORNER_BL_XLOC, CORNER_BL_YLOC, CORNER_BL_XSIZE, CORNER_BL_YSIZE));
	cv_sprite.setPosition(location.left - CORNER_BL_XSIZE, location.top + location.height);
	window.draw(cv_sprite);

	// Bottom Right
  cv_sprite.setTextureRect(sf::IntRect
	  (CORNER_BR_XLOC, CORNER_BR_YLOC, CORNER_BR_XSIZE, CORNER_BR_YSIZE));
	cv_sprite.setPosition(location.left + location.width, location.top + location.height);
	window.draw(cv_sprite);

  return 0;
}

void canvas::display() {}
