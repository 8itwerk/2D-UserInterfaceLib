// Tactics Game by Jeffrey Jernstrom
// Common Custom Type Definitions

#include <cstring>
#include <string>
using namespace std;

const int SKILLS = 2;
const int EQUIP = 5;

struct root_stats {
	int endurance;
	int strength;
	int spirit;
	int speed;
	int element;
	//int move;  // Implement in next ver
	//int jump;  // Implement in next ver
};

struct battle_stats {
	int hp;
	int mp;
	int attack;
	int defense;
	int ready;
	int mattack;
	int mdefense;
	int status;
};

struct char_stats {
	string name;
	int level;
	int exp;
};

struct skill {
  string name;
};

struct item {
  string name;
  string type;
};




	

