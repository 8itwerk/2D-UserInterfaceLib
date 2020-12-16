// Tactics Game UI by Jeffrey Jerstrom
// Page class for displaying basic info

enum page_parts {BG, BORDER_RIGHT, BORDER_LEFT, BORDER_TOP, BORDER_BOTTOM, CORNER_TL, CORNER_TR, CORNER_BL, CORNER_BR};

// Locations and dimension for page sprites on the UI texture
const int BGTILE_XSIZE = 100;
const int BGTILE_YSIZE = 100;
const int BGTILE_XLOC  = 25;
const int BGTILE_YLOC  = 25;

const int BORDER_RIGHT_XSIZE = 6;
const int BORDER_RIGHT_YSIZE = 100;
const int BORDER_RIGHT_XLOC  = 127;
const int BORDER_RIGHT_YLOC  = 25;

const int BORDER_LEFT_XSIZE = 3;
const int BORDER_LEFT_YSIZE = 100;
const int BORDER_LEFT_XLOC  = 20;
const int BORDER_LEFT_YLOC  = 25;

const int BORDER_TOP_XSIZE = 100;
const int BORDER_TOP_YSIZE = 3;
const int BORDER_TOP_XLOC  = 25;
const int BORDER_TOP_YLOC  = 20;

const int BORDER_BOTTOM_XSIZE = 100;
const int BORDER_BOTTOM_YSIZE = 6;
const int BORDER_BOTTOM_XLOC  = 25;
const int BORDER_BOTTOM_YLOC  = 127;

const int CORNER_TL_XSIZE = 3;
const int CORNER_TL_YSIZE = 3;
const int CORNER_TL_XLOC  = 20;
const int CORNER_TL_YLOC  = 20;

const int CORNER_BL_XSIZE = 3;
const int CORNER_BL_YSIZE = 5;
const int CORNER_BL_XLOC  = 20;
const int CORNER_BL_YLOC  = 127;

const int CORNER_TR_XSIZE = 5;
const int CORNER_TR_YSIZE = 3;
const int CORNER_TR_XLOC  = 127;
const int CORNER_TR_YLOC  = 20;

const int CORNER_BR_XSIZE = 6;
const int CORNER_BR_YSIZE = 6;
const int CORNER_BR_XLOC  = 127;
const int CORNER_BR_YLOC  = 127;
