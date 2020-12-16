// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

#include "page.h"
#include "pagedefs.h"
using namespace std;

// Remember how to do an init list?
page::page(string initTitle, sf::IntRect &initLocation)
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

int page::move(int byX, int byY)
{
  location.left += byX;
  location.top += byY;

  return 0;
}

int page::put(int toX, int toY)
{
  location.left += toX;
  location.top += toY;
  
  return 0;
}

int page::changeSize(int toX, int toY)
{
  location.width = toX;
  location.height = toY;

  return 0;
}

int page::getLocation(sf::IntRect &toAdd)
{
  toAdd.left = location.left;
  toAdd.top = location.top;
  toAdd.width = location.width;
  toAdd.height = location.height;

  return 0;
}

void page::update()
{
  // Count the number tile of Columns
  columns = location.width / BGTILE_XSIZE;
  column_rem = location.width % BGTILE_XSIZE;

  // Count the number tile rows
  rows = location.height / BGTILE_YSIZE;
  row_rem = location.height % BGTILE_XSIZE;

	return;
}

int page::draw(sf::RenderWindow &window, sf::Texture &ui_texture)
{
  drawBG(window, ui_texture); 

  drawBorder(window, ui_texture);

  drawCorners(window, ui_texture);

  return 0;
}

int page::drawBG(sf::RenderWindow &window, sf:: Texture &ui_texture)
{
  // Use update() here if client cannot be bothered

  // Set the texture
  pg_sprite.setTexture(ui_texture);

  pg_sprite.setTextureRect(sf::IntRect
    (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));

  // Draw Rows and Columns
  for (int j = 0; j < rows; ++j) {
    for (int i = 0; i < columns; ++i) {
      pg_sprite.setPosition(location.left + (i * BGTILE_XSIZE),
                            location.top + (j * BGTILE_YSIZE));
      window.draw(pg_sprite);
    }

    if (column_rem != 0) {
      // Custom tile size to make up remainder
      pg_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, column_rem, BGTILE_YSIZE));
      pg_sprite.setPosition(location.left + (columns * BGTILE_XSIZE), 
	      location.top + (j * BGTILE_YSIZE));
      window.draw(pg_sprite);
      // Reset Tile Size
      pg_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));
    }
  }

  if (row_rem != 0) {
    for (int i = 0; i < columns; ++i) {
      // Custom tile size to make up remainder
      pg_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, row_rem));
      pg_sprite.setPosition(location.left + (i * BGTILE_XSIZE), 
	      location.top + (rows * BGTILE_YSIZE));
      window.draw(pg_sprite);
    }

    if (column_rem != 0) {
      // Custom tile size to make up remainder
      pg_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, column_rem, row_rem));
      pg_sprite.setPosition(location.left + (columns * BGTILE_XSIZE), 
	      location.top + (rows * BGTILE_XSIZE));
      window.draw(pg_sprite);
      // Reset Tile Size
      pg_sprite.setTextureRect(sf::IntRect
	      (BGTILE_XLOC, BGTILE_YLOC, BGTILE_XSIZE, BGTILE_YSIZE));
    }
  }

  return 0;
}

int page::drawBorder(sf::RenderWindow & window, sf::Texture &ui_texture)
{
	// Top Border
  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_TOP_XLOC, BORDER_TOP_YLOC, BORDER_TOP_XSIZE, BORDER_TOP_YSIZE));

	for (int i = 0; i < columns; ++i) {
		pg_sprite.setPosition(location.left + (BORDER_TOP_XSIZE * i), location.top - BORDER_TOP_YSIZE);
		window.draw(pg_sprite);
	}

  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_TOP_XLOC, BORDER_TOP_YLOC, column_rem, BORDER_TOP_YSIZE));

	if (column_rem != 0) {
		pg_sprite.setPosition(location.left + (BORDER_TOP_XSIZE * columns),
			                    location.top - BORDER_TOP_YSIZE);
		window.draw(pg_sprite);
	}


	// Bottom Border
  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_BOTTOM_XLOC, BORDER_BOTTOM_YLOC, BORDER_BOTTOM_XSIZE, BORDER_BOTTOM_YSIZE));

	for (int i = 0; i < columns; ++i) {
		pg_sprite.setPosition(location.left + (BORDER_BOTTOM_XSIZE * i), 
				                  location.top + location.height);
		window.draw(pg_sprite);
	}

  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_BOTTOM_XLOC, BORDER_BOTTOM_YLOC, column_rem, BORDER_BOTTOM_YSIZE));

	if (column_rem != 0) {
		pg_sprite.setPosition(location.left + (BORDER_BOTTOM_XSIZE * columns),
			                    location.top + location.height);
		window.draw(pg_sprite);
	}
		
	// Left Border
  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_LEFT_XLOC, BORDER_LEFT_YLOC, BORDER_LEFT_XSIZE, BORDER_LEFT_YSIZE));

	for (int j = 0; j < rows; ++j) {
		pg_sprite.setPosition(location.left - BORDER_LEFT_XSIZE, 
				                  location.top + (BORDER_LEFT_YSIZE * j));
		window.draw(pg_sprite);
	}

  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_LEFT_XLOC, BORDER_LEFT_YLOC, BORDER_LEFT_XSIZE, row_rem));

	if (row_rem != 0) {
		pg_sprite.setPosition(location.left - BORDER_LEFT_XSIZE,
			                    location.top + (BORDER_LEFT_YSIZE * rows));
		window.draw(pg_sprite);
	}
		
	// Right Border
  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_RIGHT_XLOC, BORDER_RIGHT_YLOC, BORDER_RIGHT_XSIZE, BORDER_RIGHT_YSIZE));

	for (int j = 0; j < rows; ++j) {
		pg_sprite.setPosition(location.left + location.width, 
				                  location.top + (BORDER_RIGHT_YSIZE * j));
		window.draw(pg_sprite);
	}

  pg_sprite.setTextureRect(sf::IntRect
	  (BORDER_RIGHT_XLOC, BORDER_RIGHT_YLOC, BORDER_RIGHT_XSIZE, row_rem));

	if (row_rem != 0) {
		pg_sprite.setPosition(location.left + location.width,
			                    location.top + (BORDER_RIGHT_YSIZE * rows));
		window.draw(pg_sprite);
	}
		
  return 0;
}

int page::drawCorners(sf::RenderWindow & window, sf::Texture &ui_texture)
{
	// Top Left
  pg_sprite.setTextureRect(sf::IntRect
	  (CORNER_TL_XLOC, CORNER_TL_YLOC, CORNER_TL_XSIZE, CORNER_TL_YSIZE));
	pg_sprite.setPosition(location.left - CORNER_TL_XSIZE, location.top - CORNER_TL_YSIZE);
	window.draw(pg_sprite);

	// Top Right
  pg_sprite.setTextureRect(sf::IntRect
	  (CORNER_TR_XLOC, CORNER_TR_YLOC, CORNER_TR_XSIZE, CORNER_TR_YSIZE));
	pg_sprite.setPosition(location.left + location.width, location.top - CORNER_TL_YSIZE);
	window.draw(pg_sprite);

	// Bottom Left
  pg_sprite.setTextureRect(sf::IntRect
	  (CORNER_BL_XLOC, CORNER_BL_YLOC, CORNER_BL_XSIZE, CORNER_BL_YSIZE));
	pg_sprite.setPosition(location.left - CORNER_BL_XSIZE, location.top + location.height);
	window.draw(pg_sprite);

	// Bottom Right
  pg_sprite.setTextureRect(sf::IntRect
	  (CORNER_BR_XLOC, CORNER_BR_YLOC, CORNER_BR_XSIZE, CORNER_BR_YSIZE));
	pg_sprite.setPosition(location.left + location.width, location.top + location.height);
	window.draw(pg_sprite);

  return 0;
}
